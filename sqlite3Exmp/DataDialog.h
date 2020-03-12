#pragma once
#include "wx/wx.h"
#include "DBManager.h"
#include "wx/listctrl.h"
#include "wx/dataview.h"

namespace ExmpApp {
    class DataDialog : public wxDialog
    {
    public:
        DataDialog(wxWindow* parent, const wxString& title, const wxSize& size, DBManager* dBM);
        ~DataDialog();
        void OnClose(wxCloseEvent& event);

    private:
        std::vector<Result> results;



        //DECLARE_EVENT_TABLE();


    };

}
