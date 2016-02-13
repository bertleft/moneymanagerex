// -*- C++ -*-
//=============================================================================
/**
 *      Copyright (c) 2013 - 2016 Guan Lisheng (guanlisheng@gmail.com)
 *
 *      @file
 *
 *      @author [sqlite2cpp.py]
 *
 *      @brief
 *
 *      Revision History:
 *          AUTO GENERATED at 2016-02-13 20:35:13.516394.
 *          DO NOT EDIT!
 */
//=============================================================================

#ifndef DB_TABLE_CURRENCYFORMATS_V1_H
#define DB_TABLE_CURRENCYFORMATS_V1_H

#include "DB_Table.h"

struct DB_Table_CURRENCYFORMATS_V1 : public DB_Table
{
    struct Data;
    typedef DB_Table_CURRENCYFORMATS_V1 Self;
    /** A container to hold list of Data records for the table*/
    struct Data_Set : public std::vector<Self::Data>
    {
        std::wstring to_json() const
        {
            json::Array a;
            for (const auto & item: *this)
            {
                json::Object o;
                item.to_json(o);
                a.Insert(o);
            }
            std::wstringstream ss;
            json::Writer::Write(a, ss);
            return ss.str();
        }
    };
    /** A container to hold a list of Data record pointers for the table in memory*/
    typedef std::vector<Self::Data*> Cache;
    typedef std::map<int, Self::Data*> Index_By_Id;
    Cache cache_;
    Index_By_Id index_by_id_;
    Data* fake_; // in case the entity not found

    /** Destructor: clears any data records stored in memory */
    ~DB_Table_CURRENCYFORMATS_V1() 
    {
        delete this->fake_;
        destroy_cache();
    }
     
    /** Removes all records stored in memory (cache) for the table*/ 
    void destroy_cache()
    {
        std::for_each(cache_.begin(), cache_.end(), std::mem_fun(&Data::destroy));
        cache_.clear();
        index_by_id_.clear(); // no memory release since it just stores pointer and the according objects are in cache
    }

    /** Creates the database table if the table does not exist*/
    bool ensure(wxSQLite3Database* db)
    {
        if (!exists(db))
        {
            try
            {
                db->ExecuteUpdate("CREATE TABLE CURRENCYFORMATS_V1(CURRENCYID integer primary key, CURRENCYNAME TEXT COLLATE NOCASE NOT NULL UNIQUE, PFX_SYMBOL TEXT, SFX_SYMBOL TEXT, DECIMAL_POINT TEXT, GROUP_SEPARATOR TEXT, UNIT_NAME TEXT COLLATE NOCASE, CENT_NAME TEXT COLLATE NOCASE, SCALE integer, BASECONVRATE numeric, CURRENCY_SYMBOL TEXT COLLATE NOCASE NOT NULL UNIQUE)");
            }
            catch(const wxSQLite3Exception &e) 
            { 
                wxLogError("CURRENCYFORMATS_V1: Exception %s", e.GetMessage().c_str());
                return false;
            }
            this->ensure_data(db);
        }

        this->ensure_index(db);

        return true;
    }

    bool ensure_index(wxSQLite3Database* db)
    {
        try
        {
            db->ExecuteUpdate("CREATE INDEX IF NOT EXISTS IDX_CURRENCYFORMATS_SYMBOL ON CURRENCYFORMATS_V1(CURRENCY_SYMBOL)");
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("CURRENCYFORMATS_V1: Exception %s", e.GetMessage().c_str());
            return false;
        }

        return true;
    }

    bool ensure_data(wxSQLite3Database* db)
    {
        try
        {
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (1, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("United States dollar"), wxTRANSLATE("$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("USD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (2, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("European euro"), wxTRANSLATE("€"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("EUR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (3, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("UK Pound"), wxTRANSLATE("£"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE("Pound"), wxTRANSLATE("Pence"), wxTRANSLATE("GBP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (4, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Russian Ruble"), wxTRANSLATE(""), wxTRANSLATE("р"), wxTRANSLATE(","), wxTRANSLATE(" "), wxTRANSLATE("руб."), wxTRANSLATE("коп."), wxTRANSLATE("RUB")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (5, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Ukrainian hryvnia"), wxTRANSLATE("₴"), wxTRANSLATE(""), wxTRANSLATE(","), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("UAH")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (6, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Afghan afghani"), wxTRANSLATE("؋"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE("pul"), wxTRANSLATE("AFN")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (7, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Albanian lek"), wxTRANSLATE(""), wxTRANSLATE("L"), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("ALL")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (8, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Algerian dinar"), wxTRANSLATE("دج"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("DZD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (9, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Angolan kwanza"), wxTRANSLATE(""), wxTRANSLATE("Kz"), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE("Céntimo"), wxTRANSLATE("AOA")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (10, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("East Caribbean dollar"), wxTRANSLATE("EC$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("XCD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (11, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Argentine peso"), wxTRANSLATE("AR$"), wxTRANSLATE(""), wxTRANSLATE(","), wxTRANSLATE("."), wxTRANSLATE(""), wxTRANSLATE("centavo"), wxTRANSLATE("ARS")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (12, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Armenian dram"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("AMD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (13, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Aruban florin"), wxTRANSLATE("ƒ"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("AWG")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (14, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Australian dollar"), wxTRANSLATE("$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(","), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("AUD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (15, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Azerbaijani manat"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("AZN")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (16, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Bahamian dollar"), wxTRANSLATE("B$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BSD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (17, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Bahraini dinar"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BHD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (18, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Bangladeshi taka"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BDT")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (19, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Barbadian dollar"), wxTRANSLATE("Bds$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BBD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (20, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Belarusian ruble"), wxTRANSLATE("Br"), wxTRANSLATE(""), wxTRANSLATE(","), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BYR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (21, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Belize dollar"), wxTRANSLATE("BZ$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BZD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (22, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("West African CFA franc"), wxTRANSLATE("CFA"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("XOF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (23, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Bermudian dollar"), wxTRANSLATE("BD$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BMD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (24, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Bhutanese ngultrum"), wxTRANSLATE("Nu."), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BTN")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (25, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Bolivian boliviano"), wxTRANSLATE("Bs."), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BOB")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (26, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Bosnia and Herzegovina konvertibilna marka"), wxTRANSLATE("KM"), wxTRANSLATE(""), wxTRANSLATE(","), wxTRANSLATE("."), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BAM")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (27, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Botswana pula"), wxTRANSLATE("P"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BWP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (28, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Brazilian real"), wxTRANSLATE("R$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BRL")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (29, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Brunei dollar"), wxTRANSLATE("B$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BND")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (30, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Bulgarian lev"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BGN")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (31, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Burundi franc"), wxTRANSLATE("FBu"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("BIF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (32, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Cambodian riel"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("KHR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (33, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Central African CFA franc"), wxTRANSLATE("CFA"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("XAF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (34, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Canadian dollar"), wxTRANSLATE("$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("CAD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (35, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Cape Verdean escudo"), wxTRANSLATE("Esc"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("CVE")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (36, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Cayman Islands dollar"), wxTRANSLATE("KY$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("KYD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (37, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Chilean peso"), wxTRANSLATE("$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("CLP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (38, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Chinese renminbi"), wxTRANSLATE("¥"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("CNY")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (39, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Colombian peso"), wxTRANSLATE("Col$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("COP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (40, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Comorian franc"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("KMF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (41, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Congolese franc"), wxTRANSLATE("F"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("CDF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (42, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Costa Rican colon"), wxTRANSLATE("₡"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("CRC")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (43, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Croatian kuna"), wxTRANSLATE("kn"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("HRK")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (44, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Czech koruna"), wxTRANSLATE("Kč"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("CZK")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (45, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Danish krone"), wxTRANSLATE("Kr"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("DKK")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (46, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Djiboutian franc"), wxTRANSLATE("Fdj"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("DJF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (47, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Dominican peso"), wxTRANSLATE("RD$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("DOP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (48, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Egyptian pound"), wxTRANSLATE("£"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("EGP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (49, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Eritrean nakfa"), wxTRANSLATE("Nfa"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("ERN")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (50, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Ethiopian birr"), wxTRANSLATE("Br"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("ETB")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (51, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Falkland Islands pound"), wxTRANSLATE("£"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("FKP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (52, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Fijian dollar"), wxTRANSLATE("FJ$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("FJD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (53, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("CFP franc"), wxTRANSLATE("F"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("XPF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (54, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Gambian dalasi"), wxTRANSLATE("D"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("GMD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (55, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Georgian lari"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("GEL")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (56, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Ghanaian cedi"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("GHS")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (57, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Gibraltar pound"), wxTRANSLATE("£"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("GIP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (58, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Guatemalan quetzal"), wxTRANSLATE("Q"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("GTQ")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (59, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Guinean franc"), wxTRANSLATE("FG"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("GNF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (60, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Guyanese dollar"), wxTRANSLATE("GY$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("GYD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (61, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Haitian gourde"), wxTRANSLATE("G"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("HTG")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (62, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Honduran lempira"), wxTRANSLATE("L"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("HNL")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (63, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Hong Kong dollar"), wxTRANSLATE("HK$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("HKD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (64, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Hungarian forint"), wxTRANSLATE("Ft"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("HUF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (65, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Icelandic króna"), wxTRANSLATE("kr"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("ISK")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (66, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Indian rupee"), wxTRANSLATE("₹"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("INR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (67, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Indonesian rupiah"), wxTRANSLATE("Rp"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("IDR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (68, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Special Drawing Rights"), wxTRANSLATE("SDR"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("XDR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (69, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Iranian rial"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("IRR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (70, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Iraqi dinar"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("IQD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (71, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Israeli new sheqel"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("ILS")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (72, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Jamaican dollar"), wxTRANSLATE("J$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("JMD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (73, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Japanese yen"), wxTRANSLATE("¥"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("JPY")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (74, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Jordanian dinar"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("JOD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (75, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Kazakhstani tenge"), wxTRANSLATE("T"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("KZT")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (76, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Kenyan shilling"), wxTRANSLATE("KSh"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("KES")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (77, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("North Korean won"), wxTRANSLATE("W"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("KPW")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (78, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("South Korean won"), wxTRANSLATE("W"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("KRW")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (79, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Kuwaiti dinar"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("KWD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (80, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Kyrgyzstani som"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("KGS")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (81, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Lao kip"), wxTRANSLATE("KN"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("LAK")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (82, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Latvian lats"), wxTRANSLATE("Ls"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("LVL")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (83, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Lebanese lira"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("LBP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (84, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Lesotho loti"), wxTRANSLATE("M"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("LSL")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (85, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Liberian dollar"), wxTRANSLATE("L$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("LRD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (86, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Libyan dinar"), wxTRANSLATE("LD"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("LYD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (87, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Lithuanian litas"), wxTRANSLATE("Lt"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("LTL")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (88, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Macanese pataca"), wxTRANSLATE("P"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MOP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (89, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Macedonian denar"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MKD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (90, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Malagasy ariary"), wxTRANSLATE("FMG"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MGA")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (91, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Malawian kwacha"), wxTRANSLATE("MK"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MWK")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (92, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Malaysian ringgit"), wxTRANSLATE("RM"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MYR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (93, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Maldivian rufiyaa"), wxTRANSLATE("Rf"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MVR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (94, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Mauritanian ouguiya"), wxTRANSLATE("UM"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MRO")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (95, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Mauritian rupee"), wxTRANSLATE("Rs"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MUR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (96, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Mexican peso"), wxTRANSLATE("$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MXN")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (97, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Moldovan leu"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MDL")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (98, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Mongolian tugrik"), wxTRANSLATE("₮"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MNT")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (99, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Moroccan dirham"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MAD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (100, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Myanma kyat"), wxTRANSLATE("K"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("MMK")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (101, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Namibian dollar"), wxTRANSLATE("N$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("NAD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (102, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Nepalese rupee"), wxTRANSLATE("NRs"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("NPR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (103, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Netherlands Antillean gulden"), wxTRANSLATE("NAƒ"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("ANG")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (104, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("New Zealand dollar"), wxTRANSLATE("NZ$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("NZD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (105, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Nicaraguan córdoba"), wxTRANSLATE("C$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("NIO")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (106, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Nigerian naira"), wxTRANSLATE("₦"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("NGN")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (107, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Norwegian krone"), wxTRANSLATE("kr"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("NOK")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (108, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Omani rial"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("OMR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (109, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Pakistani rupee"), wxTRANSLATE("Rs."), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("PKR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (110, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Panamanian balboa"), wxTRANSLATE("B./"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("PAB")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (111, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Papua New Guinean kina"), wxTRANSLATE("K"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("PGK")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (112, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Paraguayan guarani"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("PYG")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (113, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Peruvian nuevo sol"), wxTRANSLATE("S/."), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("PEN")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (114, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Philippine peso"), wxTRANSLATE("₱"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("PHP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (115, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Polish zloty"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("PLN")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (116, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Qatari riyal"), wxTRANSLATE("QR"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("QAR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (117, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Romanian leu"), wxTRANSLATE("L"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("RON")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (118, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Rwandan franc"), wxTRANSLATE("RF"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("RWF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (119, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("São Tomé and Príncipe dobra"), wxTRANSLATE("Db"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("STD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (120, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Saudi riyal"), wxTRANSLATE("SR"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SAR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (121, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Serbian dinar"), wxTRANSLATE("din."), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("RSD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (122, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Seychellois rupee"), wxTRANSLATE("SR"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SCR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (123, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Sierra Leonean leone"), wxTRANSLATE("Le"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SLL")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (124, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Singapore dollar"), wxTRANSLATE("S$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SGD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (125, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Solomon Islands dollar"), wxTRANSLATE("SI$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SBD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (126, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Somali shilling"), wxTRANSLATE("Sh."), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SOS")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (127, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("South African rand"), wxTRANSLATE("R"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("ZAR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (128, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Sri Lankan rupee"), wxTRANSLATE("Rs"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("LKR")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (129, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Saint Helena pound"), wxTRANSLATE("£"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SHP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (130, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Sudanese pound"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SDG")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (131, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Surinamese dollar"), wxTRANSLATE("$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SRD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (132, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Swazi lilangeni"), wxTRANSLATE("E"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SZL")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (133, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Swedish krona"), wxTRANSLATE("kr"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SEK")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (134, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Swiss franc"), wxTRANSLATE("Fr."), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("CHF")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (135, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Syrian pound"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("SYP")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (136, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("New Taiwan dollar"), wxTRANSLATE("NT$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("TWD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (137, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Tajikistani somoni"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("TJS")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (138, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Tanzanian shilling"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("TZS")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (139, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Thai baht"), wxTRANSLATE("฿"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("THB")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (140, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Trinidad and Tobago dollar"), wxTRANSLATE("TT$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("TTD")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (141, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Tunisian dinar"), wxTRANSLATE("DT"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("TND")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (142, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Turkish lira"), wxTRANSLATE("₺"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("TRY")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (143, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Turkmen manat"), wxTRANSLATE("m"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("TMT")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (144, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Ugandan shilling"), wxTRANSLATE("USh"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("UGX")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (145, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("UAE dirham"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("AED")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (146, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Uruguayan peso"), wxTRANSLATE("$U"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("UYU")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (147, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Uzbekistani som"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("UZS")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (148, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Vanuatu vatu"), wxTRANSLATE("VT"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("VUV")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (149, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Vietnamese dong"), wxTRANSLATE("₫"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("VND")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (150, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Samoan tala"), wxTRANSLATE("WS$"), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("WST")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (151, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 1, 1, '%s')", wxTRANSLATE("Yemeni rial"), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(" "), wxTRANSLATE(""), wxTRANSLATE(""), wxTRANSLATE("YER")));
            db->ExecuteUpdate(wxString::Format("INSERT INTO CURRENCYFORMATS_V1 VALUES (152, '%s', '%s', '%s', '%s', '%s', '%s', '%s', 100, 1, '%s')", wxTRANSLATE("Venezuelan Bolívar"), wxTRANSLATE("Bs."), wxTRANSLATE(""), wxTRANSLATE("."), wxTRANSLATE(","), wxTRANSLATE("bolívar"), wxTRANSLATE("céntimos"), wxTRANSLATE("VEF")));
        }
        catch(const wxSQLite3Exception & e)
        {
            wxLogError("CURRENCYFORMATS_V1: Exception %s", e.GetMessage().c_str());
            return false;
        }

        return true;
    }
    struct CURRENCYID : public DB_Column<int>
    { 
        static wxString name() { return "CURRENCYID"; } 
        explicit CURRENCYID(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    struct CURRENCYNAME : public DB_Column<wxString>
    { 
        static wxString name() { return "CURRENCYNAME"; } 
        explicit CURRENCYNAME(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct PFX_SYMBOL : public DB_Column<wxString>
    { 
        static wxString name() { return "PFX_SYMBOL"; } 
        explicit PFX_SYMBOL(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct SFX_SYMBOL : public DB_Column<wxString>
    { 
        static wxString name() { return "SFX_SYMBOL"; } 
        explicit SFX_SYMBOL(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct DECIMAL_POINT : public DB_Column<wxString>
    { 
        static wxString name() { return "DECIMAL_POINT"; } 
        explicit DECIMAL_POINT(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct GROUP_SEPARATOR : public DB_Column<wxString>
    { 
        static wxString name() { return "GROUP_SEPARATOR"; } 
        explicit GROUP_SEPARATOR(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct UNIT_NAME : public DB_Column<wxString>
    { 
        static wxString name() { return "UNIT_NAME"; } 
        explicit UNIT_NAME(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct CENT_NAME : public DB_Column<wxString>
    { 
        static wxString name() { return "CENT_NAME"; } 
        explicit CENT_NAME(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct SCALE : public DB_Column<int>
    { 
        static wxString name() { return "SCALE"; } 
        explicit SCALE(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    struct BASECONVRATE : public DB_Column<double>
    { 
        static wxString name() { return "BASECONVRATE"; } 
        explicit BASECONVRATE(const double &v, OP op = EQUAL): DB_Column<double>(v, op) {}
    };
    struct CURRENCY_SYMBOL : public DB_Column<wxString>
    { 
        static wxString name() { return "CURRENCY_SYMBOL"; } 
        explicit CURRENCY_SYMBOL(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    typedef CURRENCYID PRIMARY;
    enum COLUMN
    {
        COL_CURRENCYID = 0
        , COL_CURRENCYNAME = 1
        , COL_PFX_SYMBOL = 2
        , COL_SFX_SYMBOL = 3
        , COL_DECIMAL_POINT = 4
        , COL_GROUP_SEPARATOR = 5
        , COL_UNIT_NAME = 6
        , COL_CENT_NAME = 7
        , COL_SCALE = 8
        , COL_BASECONVRATE = 9
        , COL_CURRENCY_SYMBOL = 10
    };

    /** Returns the column name as a string*/
    static wxString column_to_name(COLUMN col)
    {
        switch(col)
        {
            case COL_CURRENCYID: return "CURRENCYID";
            case COL_CURRENCYNAME: return "CURRENCYNAME";
            case COL_PFX_SYMBOL: return "PFX_SYMBOL";
            case COL_SFX_SYMBOL: return "SFX_SYMBOL";
            case COL_DECIMAL_POINT: return "DECIMAL_POINT";
            case COL_GROUP_SEPARATOR: return "GROUP_SEPARATOR";
            case COL_UNIT_NAME: return "UNIT_NAME";
            case COL_CENT_NAME: return "CENT_NAME";
            case COL_SCALE: return "SCALE";
            case COL_BASECONVRATE: return "BASECONVRATE";
            case COL_CURRENCY_SYMBOL: return "CURRENCY_SYMBOL";
            default: break;
        }
        
        return "UNKNOWN";
    }

    /** Returns the column number from the given column name*/
    static COLUMN name_to_column(const wxString& name)
    {
        if ("CURRENCYID" == name) return COL_CURRENCYID;
        else if ("CURRENCYNAME" == name) return COL_CURRENCYNAME;
        else if ("PFX_SYMBOL" == name) return COL_PFX_SYMBOL;
        else if ("SFX_SYMBOL" == name) return COL_SFX_SYMBOL;
        else if ("DECIMAL_POINT" == name) return COL_DECIMAL_POINT;
        else if ("GROUP_SEPARATOR" == name) return COL_GROUP_SEPARATOR;
        else if ("UNIT_NAME" == name) return COL_UNIT_NAME;
        else if ("CENT_NAME" == name) return COL_CENT_NAME;
        else if ("SCALE" == name) return COL_SCALE;
        else if ("BASECONVRATE" == name) return COL_BASECONVRATE;
        else if ("CURRENCY_SYMBOL" == name) return COL_CURRENCY_SYMBOL;

        return COLUMN(-1);
    }
    
    /** Data is a single record in the database table*/
    struct Data
    {
        friend struct DB_Table_CURRENCYFORMATS_V1;
        /** This is a instance pointer to itself in memory. */
        Self* table_;
    
        int CURRENCYID;//  primary key
        wxString CURRENCYNAME;
        wxString PFX_SYMBOL;
        wxString SFX_SYMBOL;
        wxString DECIMAL_POINT;
        wxString GROUP_SEPARATOR;
        wxString UNIT_NAME;
        wxString CENT_NAME;
        int SCALE;
        double BASECONVRATE;
        wxString CURRENCY_SYMBOL;
        int id() const { return CURRENCYID; }
        void id(int id) { CURRENCYID = id; }
        bool operator < (const Data& r) const
        {
            return this->id() < r.id();
        }
        bool operator < (const Data* r) const
        {
            return this->id() < r->id();
        }

        explicit Data(Self* table = 0) 
        {
            table_ = table;
        
            CURRENCYID = -1;
            SCALE = -1;
            BASECONVRATE = 0.0;
        }

        explicit Data(wxSQLite3ResultSet& q, Self* table = 0)
        {
            table_ = table;
        
            CURRENCYID = q.GetInt(0); // CURRENCYID
            CURRENCYNAME = q.GetString(1); // CURRENCYNAME
            PFX_SYMBOL = q.GetString(2); // PFX_SYMBOL
            SFX_SYMBOL = q.GetString(3); // SFX_SYMBOL
            DECIMAL_POINT = q.GetString(4); // DECIMAL_POINT
            GROUP_SEPARATOR = q.GetString(5); // GROUP_SEPARATOR
            UNIT_NAME = q.GetString(6); // UNIT_NAME
            CENT_NAME = q.GetString(7); // CENT_NAME
            SCALE = q.GetInt(8); // SCALE
            BASECONVRATE = q.GetDouble(9); // BASECONVRATE
            CURRENCY_SYMBOL = q.GetString(10); // CURRENCY_SYMBOL
        }

        Data& operator=(const Data& other)
        {
            if (this == &other) return *this;

            CURRENCYID = other.CURRENCYID;
            CURRENCYNAME = other.CURRENCYNAME;
            PFX_SYMBOL = other.PFX_SYMBOL;
            SFX_SYMBOL = other.SFX_SYMBOL;
            DECIMAL_POINT = other.DECIMAL_POINT;
            GROUP_SEPARATOR = other.GROUP_SEPARATOR;
            UNIT_NAME = other.UNIT_NAME;
            CENT_NAME = other.CENT_NAME;
            SCALE = other.SCALE;
            BASECONVRATE = other.BASECONVRATE;
            CURRENCY_SYMBOL = other.CURRENCY_SYMBOL;
            return *this;
        }

        template<typename C>
        bool match(const C &c) const
        {
            return false;
        }
        bool match(const Self::CURRENCYID &in) const
        {
            return this->CURRENCYID == in.v_;
        }
        bool match(const Self::CURRENCYNAME &in) const
        {
            return this->CURRENCYNAME.CmpNoCase(in.v_) == 0;
        }
        bool match(const Self::PFX_SYMBOL &in) const
        {
            return this->PFX_SYMBOL.CmpNoCase(in.v_) == 0;
        }
        bool match(const Self::SFX_SYMBOL &in) const
        {
            return this->SFX_SYMBOL.CmpNoCase(in.v_) == 0;
        }
        bool match(const Self::DECIMAL_POINT &in) const
        {
            return this->DECIMAL_POINT.CmpNoCase(in.v_) == 0;
        }
        bool match(const Self::GROUP_SEPARATOR &in) const
        {
            return this->GROUP_SEPARATOR.CmpNoCase(in.v_) == 0;
        }
        bool match(const Self::UNIT_NAME &in) const
        {
            return this->UNIT_NAME.CmpNoCase(in.v_) == 0;
        }
        bool match(const Self::CENT_NAME &in) const
        {
            return this->CENT_NAME.CmpNoCase(in.v_) == 0;
        }
        bool match(const Self::SCALE &in) const
        {
            return this->SCALE == in.v_;
        }
        bool match(const Self::BASECONVRATE &in) const
        {
            return this->BASECONVRATE == in.v_;
        }
        bool match(const Self::CURRENCY_SYMBOL &in) const
        {
            return this->CURRENCY_SYMBOL.CmpNoCase(in.v_) == 0;
        }
        wxString to_json() const
        {
            json::Object o;
            this->to_json(o);
            std::wstringstream ss;
            json::Writer::Write(o, ss);
            return ss.str();
        }
        
        int to_json(json::Object& o) const
        {
            o[L"CURRENCYID"] = json::Number(this->CURRENCYID);
            o[L"CURRENCYNAME"] = json::String(this->CURRENCYNAME.ToStdWstring());
            o[L"PFX_SYMBOL"] = json::String(this->PFX_SYMBOL.ToStdWstring());
            o[L"SFX_SYMBOL"] = json::String(this->SFX_SYMBOL.ToStdWstring());
            o[L"DECIMAL_POINT"] = json::String(this->DECIMAL_POINT.ToStdWstring());
            o[L"GROUP_SEPARATOR"] = json::String(this->GROUP_SEPARATOR.ToStdWstring());
            o[L"UNIT_NAME"] = json::String(this->UNIT_NAME.ToStdWstring());
            o[L"CENT_NAME"] = json::String(this->CENT_NAME.ToStdWstring());
            o[L"SCALE"] = json::Number(this->SCALE);
            o[L"BASECONVRATE"] = json::Number(this->BASECONVRATE);
            o[L"CURRENCY_SYMBOL"] = json::String(this->CURRENCY_SYMBOL.ToStdWstring());
            return 0;
        }
        row_t to_row_t() const
        {
            row_t row;
            row(L"CURRENCYID") = CURRENCYID;
            row(L"CURRENCYNAME") = CURRENCYNAME;
            row(L"PFX_SYMBOL") = PFX_SYMBOL;
            row(L"SFX_SYMBOL") = SFX_SYMBOL;
            row(L"DECIMAL_POINT") = DECIMAL_POINT;
            row(L"GROUP_SEPARATOR") = GROUP_SEPARATOR;
            row(L"UNIT_NAME") = UNIT_NAME;
            row(L"CENT_NAME") = CENT_NAME;
            row(L"SCALE") = SCALE;
            row(L"BASECONVRATE") = BASECONVRATE;
            row(L"CURRENCY_SYMBOL") = CURRENCY_SYMBOL;
            return row;
        }
        void to_template(html_template& t) const
        {
            t(L"CURRENCYID") = CURRENCYID;
            t(L"CURRENCYNAME") = CURRENCYNAME;
            t(L"PFX_SYMBOL") = PFX_SYMBOL;
            t(L"SFX_SYMBOL") = SFX_SYMBOL;
            t(L"DECIMAL_POINT") = DECIMAL_POINT;
            t(L"GROUP_SEPARATOR") = GROUP_SEPARATOR;
            t(L"UNIT_NAME") = UNIT_NAME;
            t(L"CENT_NAME") = CENT_NAME;
            t(L"SCALE") = SCALE;
            t(L"BASECONVRATE") = BASECONVRATE;
            t(L"CURRENCY_SYMBOL") = CURRENCY_SYMBOL;
        }

        /** Save the record instance in memory to the database. */
        bool save(wxSQLite3Database* db)
        {
            if (db && db->IsReadOnly()) return false;
            if (!table_ || !db) 
            {
                wxLogError("can not save CURRENCYFORMATS_V1");
                return false;
            }

            return table_->save(this, db);
        }

        /** Remove the record instance from memory and the database. */
        bool remove(wxSQLite3Database* db)
        {
            if (!table_ || !db) 
            {
                wxLogError("can not remove CURRENCYFORMATS_V1");
                return false;
            }
            
            return table_->remove(this, db);
        }

        void destroy()
        {
            //if (this->id() < 0)
            //    wxSafeShowMessage("unsaved object", this->to_json());
            delete this;
        }
    };

    enum
    {
        NUM_COLUMNS = 11
    };

    size_t num_columns() const { return NUM_COLUMNS; }

    /** Name of the table*/    
    wxString name() const { return "CURRENCYFORMATS_V1"; }

    DB_Table_CURRENCYFORMATS_V1() : fake_(new Data())
    {
        query_ = "SELECT * FROM CURRENCYFORMATS_V1 ";
    }

    /** Create a new Data record and add to memory table (cache)*/
    Self::Data* create()
    {
        Self::Data* entity = new Self::Data(this);
        cache_.push_back(entity);
        return entity;
    }
    
    /** Create a copy of the Data record and add to memory table (cache)*/
    Self::Data* clone(const Data* e)
    {
        Self::Data* entity = create();
        *entity = *e;
        entity->id(-1);
        return entity;
    }

    /**
    * Saves the Data record to the database table.
    * Either create a new record or update the existing record.
    * Remove old record from the memory table (cache)
    */
    bool save(Self::Data* entity, wxSQLite3Database* db)
    {
        wxString sql = wxEmptyString;
        if (entity->id() <= 0) //  new & insert
        {
            sql = "INSERT INTO CURRENCYFORMATS_V1(CURRENCYNAME, PFX_SYMBOL, SFX_SYMBOL, DECIMAL_POINT, GROUP_SEPARATOR, UNIT_NAME, CENT_NAME, SCALE, BASECONVRATE, CURRENCY_SYMBOL) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        }
        else
        {
            sql = "UPDATE CURRENCYFORMATS_V1 SET CURRENCYNAME = ?, PFX_SYMBOL = ?, SFX_SYMBOL = ?, DECIMAL_POINT = ?, GROUP_SEPARATOR = ?, UNIT_NAME = ?, CENT_NAME = ?, SCALE = ?, BASECONVRATE = ?, CURRENCY_SYMBOL = ? WHERE CURRENCYID = ?";
        }

        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(sql);

            stmt.Bind(1, entity->CURRENCYNAME);
            stmt.Bind(2, entity->PFX_SYMBOL);
            stmt.Bind(3, entity->SFX_SYMBOL);
            stmt.Bind(4, entity->DECIMAL_POINT);
            stmt.Bind(5, entity->GROUP_SEPARATOR);
            stmt.Bind(6, entity->UNIT_NAME);
            stmt.Bind(7, entity->CENT_NAME);
            stmt.Bind(8, entity->SCALE);
            stmt.Bind(9, entity->BASECONVRATE);
            stmt.Bind(10, entity->CURRENCY_SYMBOL);
            if (entity->id() > 0)
                stmt.Bind(11, entity->CURRENCYID);

            stmt.ExecuteUpdate();
            stmt.Finalize();

            if (entity->id() > 0) // existent
            {
                for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
                {
                    Self::Data* e = *it;
                    if (e->id() == entity->id()) 
                        *e = *entity;  // in-place update
                }
            }
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("CURRENCYFORMATS_V1: Exception %s, %s", e.GetMessage().c_str(), entity->to_json());
            return false;
        }

        if (entity->id() <= 0)
        {
            entity->id((db->GetLastRowId()).ToLong());
            index_by_id_.insert(std::make_pair(entity->id(), entity));
        }
        return true;
    }

    /** Remove the Data record from the database and the memory table (cache) */
    bool remove(int id, wxSQLite3Database* db)
    {
        if (id <= 0) return false;
        try
        {
            wxString sql = "DELETE FROM CURRENCYFORMATS_V1 WHERE CURRENCYID = ?";
            wxSQLite3Statement stmt = db->PrepareStatement(sql);
            stmt.Bind(1, id);
            stmt.ExecuteUpdate();
            stmt.Finalize();

            Cache c;
            for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
            {
                Self::Data* entity = *it;
                if (entity->id() == id) 
                {
                    index_by_id_.erase(entity->id());
                    delete entity;
                }
                else 
                {
                    c.push_back(entity);
                }
            }
            cache_.clear();
            cache_.swap(c);
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("CURRENCYFORMATS_V1: Exception %s", e.GetMessage().c_str());
            return false;
        }

        return true;
    }

    /** Remove the Data record from the database and the memory table (cache) */
    bool remove(Self::Data* entity, wxSQLite3Database* db)
    {
        if (remove(entity->id(), db))
        {
            entity->id(-1);
            return true;
        }

        return false;
    }

    template<typename... Args>
    Self::Data* get_one(const Args& ... args)
    {
        for (Index_By_Id::iterator it = index_by_id_.begin(); it != index_by_id_.end(); ++ it)
        {
            Self::Data* item = it->second;
            if (item->id() > 0 && match(item, args...)) 
            {
                ++ hit_;
                return item;
            }
        }

        ++ miss_;

        return 0;
    }
    
    /**
    * Search the memory table (Cache) for the data record.
    * If not found in memory, search the database and update the cache.
    */
    Self::Data* get(int id, wxSQLite3Database* db)
    {
        if (id <= 0) 
        {
            ++ skip_;
            return 0;
        }

        Index_By_Id::iterator it = index_by_id_.find(id);
        if (it != index_by_id_.end())
        {
            ++ hit_;
            return it->second;
        }
        
        ++ miss_;
        Self::Data* entity = 0;
        wxString where = wxString::Format(" WHERE %s = ?", PRIMARY::name().c_str());
        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(this->query() + where);
            stmt.Bind(1, id);

            wxSQLite3ResultSet q = stmt.ExecuteQuery();
            if(q.NextRow())
            {
                entity = new Self::Data(q, this);
                cache_.push_back(entity);
                index_by_id_.insert(std::make_pair(id, entity));
            }
            stmt.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().c_str(), e.GetMessage().c_str());
        }
        
        if (!entity) 
        {
            entity = this->fake_;
            // wxLogError("%s: %d not found", this->name().c_str(), id);
        }
 
        return entity;
    }

    /**
    * Return a list of Data records (Data_Set) derived directly from the database.
    * The Data_Set is sorted based on the column number.
    */
    const Data_Set all(wxSQLite3Database* db, COLUMN col = COLUMN(0), bool asc = true)
    {
        Data_Set result;
        try
        {
            wxSQLite3ResultSet q = db->ExecuteQuery(col == COLUMN(0) ? this->query() : this->query() + " ORDER BY " + column_to_name(col) + " COLLATE NOCASE " + (asc ? " ASC " : " DESC "));

            while(q.NextRow())
            {
                Self::Data entity(q, this);
                result.push_back(std::move(entity));
            }

            q.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().c_str(), e.GetMessage().c_str());
        }

        return result;
    }
};
#endif //
