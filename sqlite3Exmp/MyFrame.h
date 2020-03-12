#pragma once
#include "wx/wx.h"
#include "DBManager.h"
#include "DataDialog.h"


namespace ExmpApp {

    class MyFrame : public wxFrame
    {
    public:
        MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
        ~MyFrame();
        void doSomething();
        wxTextCtrl* textCtrl;
        wxTextCtrl* textCtrl01;



    private:
        DataDialog* results;
        DBManager* dBM;
        void onButtonClicked01(wxCommandEvent& event);
        void onButtonClicked02(wxCommandEvent& event);


        //DECLARE_EVENT_TABLE();

    };

}
