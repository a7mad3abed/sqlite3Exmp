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
   

    results = new DataDialog(this, "Show results", wxSize(400,300), dBM);
    int width = 0;
    int height = 0;
    this->DoGetSize(&width, &height);

    wxPanel* panel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(300 , 100),wxALIGN_CENTER_HORIZONTAL);
    wxGridSizer* gridSizer = new wxGridSizer(2, 2, wxSize(2, 2));
    //wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    //sizer->Add(new wxStaticText(this, wxID_ANY, "Text to change",  wxDefaultPosition, wxSize(width/2, 20)), 0, 10, wxALL);
    //sizer->Add(new wxTextCtrl(this, wxID_ANY, "also must be changed", wxDefaultPosition, wxSize(width/2,20)), 0, 10 , wxALL);

    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "also must be changed", wxDefaultPosition, wxSize(width / 3, 20));
    wxTextCtrl* textCtrl01 = new wxTextCtrl(panel, wxID_ANY, "also must be changed", wxDefaultPosition, wxSize(width / 3, 20));
    wxButton* button1 = new wxButton(panel, BUTTON1, "add record");
    wxButton* button2 = new wxButton(panel, BUTTON2, "Show results");
    button1->Bind(wxEVT_BUTTON, &MyFrame::onButtonClicked01, this);
    button2->Bind(wxEVT_BUTTON, &MyFrame::onButtonClicked02, this);
    gridSizer->Add(button1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    gridSizer->Add(textCtrl, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL);
    gridSizer->Add(button2, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    gridSizer->Add(textCtrl01, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    panel->SetSizerAndFit(gridSizer);
    wxPanel* panel01 = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(300 , 100));
}

void MyFrame::onButtonClicked01(wxCommandEvent& event)
{
    dBM->add_record( "1", "Ahmed");

}

void MyFrame::onButtonClicked02(wxCommandEvent& event)
{
    results = new DataDialog(this, "Show results", wxSize(400,300), dBM);
    results->Show(true);
}

MyFrame::~MyFrame()
{
}


//
//BEGIN_EVENT_TABLE(MyFrame, wxFrame)
//    EVT_BUTTON(BUTTON1, MyFrame::onButtonClicked01)
//    EVT_BUTTON(BUTTON2, MyFrame::onButtonClicked02)
//END_EVENT_TABLE()
