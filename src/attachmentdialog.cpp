/*******************************************************
Copyright (C) 2014 Gabriele-V

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ********************************************************/

#include "attachmentdialog.h"
#include "constants.h"
#include "paths.h"
#include "util.h"

#include "model/Model_Attachment.h"
#include "model/Model_Infotable.h"

#include <wx/mimetype.h>

IMPLEMENT_DYNAMIC_CLASS( mmAttachmentDialog, wxDialog )

BEGIN_EVENT_TABLE( mmAttachmentDialog, wxDialog )
    EVT_BUTTON(wxID_CANCEL, mmAttachmentDialog::OnCancel)
    EVT_BUTTON(wxID_OK, mmAttachmentDialog::OnOk)
    EVT_DATAVIEW_SELECTION_CHANGED(wxID_ANY, mmAttachmentDialog::OnListItemSelected)
    EVT_DATAVIEW_ITEM_CONTEXT_MENU(wxID_ANY, mmAttachmentDialog::OnItemRightClick)
	EVT_MENU_RANGE(MENU_NEW_ATTACHMENT, MENU_DELETE_ATTACHMENT, mmAttachmentDialog::OnMenuSelected)
	EVT_DATAVIEW_ITEM_ACTIVATED(wxID_ANY, mmAttachmentDialog::OnListItemActivated)
END_EVENT_TABLE()


mmAttachmentDialog::mmAttachmentDialog (wxWindow* parent, const wxString& RefType, const int& RefId) :
    m_attachment_id(-1)
	, m_RefType(RefType)
	, m_RefId(RefId)
#ifdef __WXMSW__
    , debug_(__WXDEBUG__)
#else
    , debug_(WXDEBUG)
#endif
{
    if (debug_) ColName_[ATTACHMENT_ID] = _("#");
    ColName_[ATTACHMENT_DESCRIPTION] = _("Description");
    ColName_[ATTACHMENT_FILENAME] = _("File");

	do_create(parent);

    wxString AttachmentsFolder = mmex::getPathAttachment(Model_Infotable::instance().GetStringInfo("ATTACHMENTSFOLDER:" + mmPlatformType(), ""));

	if (AttachmentsFolder == wxEmptyString)
	{
		wxString msgStr = wxString() << _("Attachment folder not defined.") << "\n"
			<< _("Please set it in Tools -> Options -> Attachments") << "\n";
		wxMessageBox(msgStr, _("Attachment folder not defined"), wxICON_ERROR);
	}
	else if (!wxDirExists(AttachmentsFolder))
	{
		wxString msgStr = wxString() << _("Unable to find attachments folder:") << "\n"
			<< "'" << AttachmentsFolder << "'" << "\n"
			<< "\n"
			<< _("Please verify that above path is correct") << "\n";
		wxMessageBox(msgStr, _("Attachments folder not found"), wxICON_ERROR);
	}
}

void mmAttachmentDialog::do_create(wxWindow* parent)
{
    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    long style = wxCAPTION | wxCLOSE_BOX | wxRESIZE_BORDER;

	wxString WindowTitle;
	if (m_RefId != 0)
		WindowTitle = wxString::Format(_("Organize Attachments | %s %i"), m_RefType, m_RefId);
	else
		WindowTitle = wxString::Format(_("Organize Attachments | New %s"), m_RefType);

	if (!wxDialog::Create(parent, wxID_ANY, WindowTitle, wxDefaultPosition, wxDefaultSize, style))
		return;

    CreateControls();

    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);

    SetIcon(mmex::getProgramIcon());

    fillControls();

    Centre();
}

void mmAttachmentDialog::CreateControls()
{
    wxBoxSizer* mainBoxSizer = new wxBoxSizer(wxVERTICAL);

    attachmentListBox_ = new wxDataViewListCtrl( this
        , wxID_ANY, wxDefaultPosition, wxSize(460, 500)/*, wxDV_HORIZ_RULES*/);

    if (debug_) attachmentListBox_->AppendTextColumn(ColName_[ATTACHMENT_ID], wxDATAVIEW_CELL_INERT, 30);
	attachmentListBox_->AppendTextColumn(ColName_[ATTACHMENT_DESCRIPTION], wxDATAVIEW_CELL_INERT, 150);
    attachmentListBox_->AppendTextColumn(ColName_[ATTACHMENT_FILENAME], wxDATAVIEW_CELL_INERT, 300);
    mainBoxSizer->Add(attachmentListBox_, wxSizerFlags(g_flagsExpand).Border(wxALL, 10));

    wxPanel* buttons_panel = new wxPanel(this, wxID_ANY);
    mainBoxSizer->Add(buttons_panel, wxSizerFlags(g_flags).Center());

    wxStdDialogButtonSizer* buttons_sizer = new wxStdDialogButtonSizer;
    buttons_panel->SetSizer(buttons_sizer);

    button_OK_ = new wxButton(buttons_panel, wxID_OK, _("&OK "));
    btnCancel_ = new wxButton(buttons_panel, wxID_CANCEL, _("&Cancel "));

    buttons_sizer->Add(button_OK_, g_flags);
    buttons_sizer->Add(btnCancel_, g_flags);
    Center();
    this->SetSizer(mainBoxSizer);
}

void mmAttachmentDialog::fillControls()
{
    attachmentListBox_->DeleteAllItems();
	
	Model_Attachment::Data_Set attachments = Model_Attachment::instance().FilterAttachments(m_RefType, m_RefId);

	for (const auto &entry : attachments)
    {
		int attachmentID = entry.ATTACHMENTID;
        wxVector<wxVariant> data;
        if (debug_) data.push_back(wxVariant(wxString::Format("%i", attachmentID)));
		data.push_back(wxVariant(entry.DESCRIPTION));
		data.push_back(wxVariant(entry.REFTYPE + wxFileName::GetPathSeparator() + entry.FILENAME));
        attachmentListBox_->AppendItem(data, (wxUIntPtr)attachmentID);
        if (m_selected_index == attachmentListBox_->GetItemCount() - 1)
        {
            attachmentListBox_->SelectRow(m_selected_index);
            m_attachment_id = attachmentID;
        }
        if (m_attachment_id == attachmentID)
        {
            m_selected_index = attachmentListBox_->GetItemCount() - 1;
            attachmentListBox_->SelectRow(m_selected_index);
        }
    }

    //Ensure that the selected item is visible. 
    wxDataViewItem item(attachmentListBox_->GetCurrentItem());
    attachmentListBox_->EnsureVisible(item);
}

void mmAttachmentDialog::OnListItemSelected(wxDataViewEvent& event)
{
    wxDataViewItem item = event.GetItem();
    m_selected_index = attachmentListBox_->ItemToRow(item);

    if (m_selected_index >= 0)
        m_attachment_id = (int)attachmentListBox_->GetItemData(item);
}

void mmAttachmentDialog::AddAttachment()
{
	const wxString attachmentFilePath = wxFileSelector(_("Import attachment:")
		, wxEmptyString, wxEmptyString, wxEmptyString
		, "All Files |*.*"
		, wxFD_FILE_MUST_EXIST);

	if (attachmentFilePath.empty()) return;

	wxFileName fn(attachmentFilePath);
	const wxString attachmentFileName = fn.FileName(attachmentFilePath).GetName();
	const wxString attachmentFileExtension = fn.FileName(attachmentFilePath).GetExt().MakeLower();
	
    const wxString attachmentDescription = wxGetTextFromUser(_("Enter a description for the new attachment:")
		, _("Organize Attachments: Add Attachment"), attachmentFileName);

    wxString AttachmentsFolder = mmex::getPathAttachment(Model_Infotable::instance().GetStringInfo("ATTACHMENTSFOLDER:" + mmPlatformType(), ""));
	wxString attachmentNumberString = Model_Attachment::LastAttachmentFileName(m_RefType, m_RefId);
	attachmentNumberString = attachmentNumberString.SubString(attachmentNumberString.Find("Attach")+6, attachmentNumberString.Find(".")-1);
	int attachmentNumber = wxAtoi(attachmentNumberString);

	wxString importedFileName = m_RefType + "_" + wxString::Format("%i", m_RefId) + "_Attach" + wxString::Format("%i", attachmentNumber+1) + "." + attachmentFileExtension;

	if (mmAttachmentManage::CopyAttachment(attachmentFilePath, AttachmentsFolder + wxFileName::GetPathSeparator() + m_RefType + wxFileName::GetPathSeparator() + importedFileName))
	{
		Model_Attachment::Data* NewAttachment = Model_Attachment::instance().create();
		NewAttachment->REFTYPE = m_RefType;
		NewAttachment->REFID = m_RefId;
		NewAttachment->DESCRIPTION = attachmentDescription;
		NewAttachment->FILENAME = importedFileName;
		m_attachment_id = Model_Attachment::instance().save(NewAttachment);
		m_selected_index = -1;
	}

    fillControls();
}

void mmAttachmentDialog::OpenAttachment()
{
	Model_Attachment::Data *attachments = Model_Attachment::instance().get(m_attachment_id);
    wxString attachmentFilePath = mmex::getPathAttachment(Model_Infotable::instance().GetStringInfo("ATTACHMENTSFOLDER:" + mmPlatformType(), ""))
        + wxFileName::GetPathSeparator() + attachments->REFTYPE + wxFileName::GetPathSeparator() + attachments->FILENAME;

	mmAttachmentManage::OpenAttachment(attachmentFilePath);
}

void mmAttachmentDialog::EditAttachment()
{
	Model_Attachment::Data *attachment = Model_Attachment::instance().get(m_attachment_id);
    if (attachment)
    {
        const wxString description = wxGetTextFromUser(_("Modify the description for the attachment:")
			, _("Organize Attachments: Edit Attachment"), attachment->DESCRIPTION);
		if (description.IsEmpty()) return;

		if (description == attachment->DESCRIPTION) return;

		attachment->DESCRIPTION = description;
		m_attachment_id = Model_Attachment::instance().save(attachment);
        m_selected_index = -1;

        fillControls();
    }
}

void mmAttachmentDialog::DeleteAttachment()
{
	Model_Attachment::Data *attachments = Model_Attachment::instance().get(m_attachment_id);
    if (attachments)
    {
		int DeleteResponse = wxMessageBox(
			_("Do you really want to delete this attachment?")
			, _("Confirm Attachment Deletion")
			, wxYES_NO | wxNO_DEFAULT | wxICON_ERROR);
		if (DeleteResponse == wxYES)
		{
            wxString AttachmentsFolder = mmex::getPathAttachment(Model_Infotable::instance().GetStringInfo("ATTACHMENTSFOLDER:" + mmPlatformType(), ""))
                + wxFileName::GetPathSeparator() + attachments->REFTYPE;
			if (mmAttachmentManage::DeleteAttachment(AttachmentsFolder + wxFileName::GetPathSeparator() + attachments->FILENAME))
			{
				Model_Attachment::instance().remove(m_attachment_id);
			}
			m_attachment_id = -1;
			m_selected_index--;
			fillControls();
		}
    }
}

void mmAttachmentDialog::OnMenuSelected(wxCommandEvent& event)
{
    wxCommandEvent evt;
    int id = event.GetId();
    switch(id)
    {
        case MENU_NEW_ATTACHMENT: AddAttachment(); break;
		case MENU_OPEN_ATTACHMENT: OpenAttachment(); break;
        case MENU_EDIT_ATTACHMENT: EditAttachment(); break;
        case MENU_DELETE_ATTACHMENT: DeleteAttachment(); break;
        default: break;
    }
}

void mmAttachmentDialog::OnItemRightClick(wxDataViewEvent& event)
{
    wxCommandEvent evt(wxEVT_COMMAND_MENU_SELECTED, wxID_ANY) ;
    evt.SetEventObject( this );

	Model_Attachment::Data* attachment = Model_Attachment::instance().get(m_attachment_id);

    wxMenu* mainMenu = new wxMenu;

    mainMenu->Append(new wxMenuItem(mainMenu, MENU_NEW_ATTACHMENT, _("&Add ")));
    mainMenu->AppendSeparator();
	mainMenu->Append(new wxMenuItem(mainMenu, MENU_OPEN_ATTACHMENT, _("&Open ")));
    mainMenu->Append(new wxMenuItem(mainMenu, MENU_EDIT_ATTACHMENT, _("&Edit ")));
    mainMenu->Append(new wxMenuItem(mainMenu, MENU_DELETE_ATTACHMENT, _("&Remove ")));
	
	//Disable buttons
    wxString AttachmentsFolder = mmex::getPathAttachment(Model_Infotable::instance().GetStringInfo("ATTACHMENTSFOLDER:" + mmPlatformType(), ""));
	if (AttachmentsFolder == wxEmptyString || !wxDirExists(AttachmentsFolder))
		mainMenu->Enable(MENU_NEW_ATTACHMENT, false);

	if (!attachment)
	{
		mainMenu->Enable(MENU_OPEN_ATTACHMENT, false);
		mainMenu->Enable(MENU_EDIT_ATTACHMENT, false);
		mainMenu->Enable(MENU_DELETE_ATTACHMENT, false);
	}

    PopupMenu(mainMenu);
    delete mainMenu;
    event.Skip();
}

void mmAttachmentDialog::OnListItemActivated(wxDataViewEvent& event)
{
	Model_Attachment::Data *attachments = Model_Attachment::instance().get(m_attachment_id);
    wxString attachmentFilePath = mmex::getPathAttachment(Model_Infotable::instance().GetStringInfo("ATTACHMENTSFOLDER:" + mmPlatformType(), ""))
        + wxFileName::GetPathSeparator() + attachments->REFTYPE + wxFileName::GetPathSeparator() + attachments->FILENAME;

	mmAttachmentManage::OpenAttachment(attachmentFilePath);
}

void mmAttachmentDialog::OnCancel(wxCommandEvent& /*event*/)
{
    EndModal(wxID_CANCEL);
}

void mmAttachmentDialog::OnOk(wxCommandEvent& /*event*/)
{
    EndModal(wxID_OK);
}


/***********************
** mmAttachmentManage **
************************/
wxString mmAttachmentManage::GetAttachmentNoteSign()
{
	return "[U] ";
}

bool mmAttachmentManage::CreateReadmeFile(const wxString& FolderPath)
{
	wxString ReadmeFilePath = FolderPath + wxFileName::GetPathSeparator() + "readme.txt";
	wxString ReadmeText;
	ReadmeText << _("This directory and its files are automatically managed by Money Manager EX software.") << wxTextFile::GetEOL();
	ReadmeText << wxTextFile::GetEOL();
	ReadmeText << _("Please do not remove, rename or modify manually directories and files.") << wxTextFile::GetEOL();

	if (!wxFileExists(ReadmeFilePath))
	{
		wxFile file(ReadmeFilePath, wxFile::write);

		if (file.IsOpened())
		{
			file.Write(ReadmeText);
			file.Close();
			return true;
		}
	}

	return false;
}

bool mmAttachmentManage::CopyAttachment(const wxString& FileToImport, const wxString& ImportedFile)
{
	wxString destinationFolder = wxPathOnly(ImportedFile);

	if (!wxDirExists(destinationFolder))
	{
		if (wxMkdir(destinationFolder))
			mmAttachmentManage::CreateReadmeFile(destinationFolder);
		else
			return false;
	}

	if (wxFileExists(ImportedFile))
	{
		const auto &attachments = Model_Attachment::instance().find(Model_Attachment::FILENAME(wxFileNameFromPath(ImportedFile)));
		if (attachments.empty())
		{
			wxString msgStr = wxString() << _("Destination file already exist:") << "\n"
				<< "'" << ImportedFile << "'" << "\n"
				<< "\n"
				<< _("File not found in attachments. Please delete or rename it.") << "\n";
			wxMessageBox(msgStr, _("Destination file already exist"), wxICON_ERROR);
		}
		else
		{
			wxString msgStr = wxString() << _("Destination file already exist:") << "\n"
				<< "'" << ImportedFile << "'" << "\n"
				<< "\n"
				<< _("File already found in attachments") << "\n";
			wxMessageBox(msgStr, _("Destination file already exist"), wxICON_ERROR);
		}
		return false;
	}
	else if (wxCopyFile(FileToImport, ImportedFile))
	{
		if (Model_Infotable::instance().GetBoolInfo("ATTACHMENTSDELETE", false))
			wxRemoveFile(FileToImport);
	}
	else
		return false;

	return true;
}

bool mmAttachmentManage::DeleteAttachment(const wxString& FileToDelete)
{
	if (wxFileExists(FileToDelete))
	{
		if (Model_Infotable::instance().GetBoolInfo("ATTACHMENTSTRASH", false))
		{
            wxString DeletedAttachmentFolder = mmex::getPathAttachment(Model_Infotable::instance().GetStringInfo("ATTACHMENTSFOLDER:" + mmPlatformType(), ""))
                + wxFileName::GetPathSeparator() + "Deleted";

			if (!wxDirExists(DeletedAttachmentFolder))
			{
				if (wxMkdir(DeletedAttachmentFolder))
					mmAttachmentManage::CreateReadmeFile(DeletedAttachmentFolder);
				else
					return false;
			}

			wxString FileToTrash = DeletedAttachmentFolder + wxFileName::GetPathSeparator()
				+ wxDateTime::Now().FormatISODate() + "_" + wxFileNameFromPath(FileToDelete);

			if (!wxRenameFile(FileToDelete, FileToTrash))
				return false;
		}
		else if (!wxRemoveFile(FileToDelete))
			return false;
	}
	else
	{
		wxString msgStr = wxString() << _("Attachment not found:") << "\n"
			<< "'" << FileToDelete << "'" << "\n"
			<< "\n"
			<< _("Do you want to continue and delete attachment on database?") << "\n";
		int DeleteResponse = wxMessageBox(msgStr, _("Delete attachment failed"), wxYES_NO | wxNO_DEFAULT | wxICON_ERROR);
		if (DeleteResponse == wxYES)
			return true;
		else
			return false;
	}
	return true;
}

bool mmAttachmentManage::OpenAttachment(const wxString& FileToOpen)
{
	wxFileName fn(FileToOpen);
	const wxString FileExtension = fn.FileName(FileToOpen).GetExt();

	if (!wxFileExists(FileToOpen))
	{
		wxString msgStr = wxString() << _("Unable to open file:") << "\n"
			<< "'" << FileToOpen << "'" << "\n"
			<< "\n"
			<< _("Please verify that file exists and user has rights to read it.") << "\n";
		wxMessageBox(msgStr, _("Open attachment failed"), wxICON_ERROR);
		return false;
	}

	wxMimeTypesManager manager;
	wxFileType *filetype = manager.GetFileTypeFromExtension(FileExtension);
	if (filetype != nullptr)
	{
		wxString command = filetype->GetOpenCommand(FileToOpen);
		wxExecute(command);
		delete filetype;
	}
	else
	{
		wxString msgStr = wxString() << _("No software found for file extension .") << FileExtension <<"\n"
			<< "\n"
			<< _("Please verify that operatin system is able to handle this type of file.") << "\n";
		wxMessageBox(msgStr, _("Open attachment failed"), wxICON_ERROR);
	}
	return true;
}

bool mmAttachmentManage::DeleteAllAttachments(const wxString& RefType, const int& RefId)
{
	Model_Attachment::Data_Set attachments = Model_Attachment::instance().FilterAttachments(RefType, RefId);
    wxString AttachmentsFolder = mmex::getPathAttachment(Model_Infotable::instance().GetStringInfo("ATTACHMENTSFOLDER:" + mmPlatformType(), ""))
        + wxFileName::GetPathSeparator() + RefType;

	for (const auto &entry : attachments)
	{
		mmAttachmentManage::DeleteAttachment(AttachmentsFolder + wxFileName::GetPathSeparator() + entry.FILENAME);
		Model_Attachment::instance().remove(entry.ATTACHMENTID);
	}
	return true;
}

bool mmAttachmentManage::RelocateAllAttachments(const wxString& RefType, const int& OldRefId, const int& NewRefId)
{
	auto attachments = Model_Attachment::instance().find(Model_Attachment::DB_Table_ATTACHMENT_V1::REFTYPE(RefType), Model_Attachment::REFID(OldRefId));
    wxString AttachmentsFolder = mmex::getPathAttachment(Model_Infotable::instance().GetStringInfo("ATTACHMENTSFOLDER:" + mmPlatformType(), ""))
        + wxFileName::GetPathSeparator() + RefType + wxFileName::GetPathSeparator();

	for (auto &entry : attachments)
	{
		wxString NewFileName = entry.FILENAME;
		NewFileName.Replace(entry.REFTYPE + "_" + wxString::Format("%i", entry.REFID), entry.REFTYPE + "_" + wxString::Format("%i", NewRefId));
		wxRenameFile(AttachmentsFolder + entry.FILENAME, AttachmentsFolder + NewFileName);
		entry.REFID = NewRefId;
		entry.FILENAME = NewFileName;
		Model_Attachment::instance().save(attachments);
	}
	return true;
}

void mmAttachmentManage::OpenAttachmentFromPanelIcon(wxWindow* parent, const wxString& RefType, const int& RefId)
{
	int AttachmentsNr = Model_Attachment::instance().NrAttachments(RefType, RefId);

	if (AttachmentsNr == 1)
	{
		Model_Attachment::Data_Set attachments = Model_Attachment::instance().FilterAttachments(RefType, RefId);
        wxString attachmentFilePath = mmex::getPathAttachment(Model_Infotable::instance().GetStringInfo("ATTACHMENTSFOLDER:" + mmPlatformType(), ""))
            + wxFileName::GetPathSeparator() + attachments[0].REFTYPE + wxFileName::GetPathSeparator() + attachments[0].FILENAME;
		mmAttachmentManage::OpenAttachment(attachmentFilePath);
	}
	else
	{
		mmAttachmentDialog dlg(parent, RefType, RefId);
		dlg.ShowModal();
	}
}
