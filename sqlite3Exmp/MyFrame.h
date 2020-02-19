#pragma once
#include "wx/wx.h"
#include "DBManager.h"
#include "DataDialog.h"

class MyFrame : public wxFrame 
{
public: 
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	void doSomething();
	wxDECLARE_EVENT_TABLE();



private:
    DBManager* dBM;
    DataDialog* results;
    void onButtonClicked01(wxCommandEvent &event);
    void onButtonClicked02(wxCommandEvent &event);


    DECLARE_EVENT_TABLE();

};

