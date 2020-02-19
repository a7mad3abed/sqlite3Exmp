#include "MyFrame.h"

enum
{
    BUTTON1,
    BUTTON2
};


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    dBM = new DBManager();
    results = new DataDialog(this, "Show results", wxSize(300,200));
    int width = 0;
    int height = 0;
    this->DoGetSize(&width, &height);

    wxGridSizer* gridSizer = new wxGridSizer(2, 2, wxSize(2, 2));
    //wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    //sizer->Add(new wxStaticText(this, wxID_ANY, "Text to change",  wxDefaultPosition, wxSize(width/2, 20)), 0, 10, wxALL);
    //sizer->Add(new wxTextCtrl(this, wxID_ANY, "also must be changed", wxDefaultPosition, wxSize(width/2,20)), 0, 10 , wxALL);

    wxTextCtrl* textCtrl = new wxTextCtrl(this, wxID_ANY, "also must be changed", wxDefaultPosition, wxSize(width / 2, 20));
    wxTextCtrl* textCtrl01 = new wxTextCtrl(this, wxID_ANY, "also must be changed", wxDefaultPosition, wxSize(width / 2, 20));
    wxButton* button1 = new wxButton(this, BUTTON1, "add record");
    wxButton* button2 = new wxButton(this, BUTTON2, "Show results");
    gridSizer->Add(button1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    gridSizer->Add(textCtrl, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    gridSizer->Add(button2, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    gridSizer->Add(textCtrl01, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    SetSizer(gridSizer);
}

void MyFrame::onButtonClicked01(wxCommandEvent& event)
{
    dBM->add_record(01, "Ahmed");

}

void MyFrame::onButtonClicked02(wxCommandEvent& event)
{
    results->Show(true);
}

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(BUTTON1, MyFrame::onButtonClicked01)
    EVT_BUTTON(BUTTON2, MyFrame::onButtonClicked02)
END_EVENT_TABLE()
