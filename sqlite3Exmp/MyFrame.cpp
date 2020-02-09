#include "MyFrame.h"


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    int width = 0;
    int height = 0;
    this->DoGetSize(&width, &height);

    wxGridSizer* gridSizer = new wxGridSizer(2, 2, wxSize(2, 2));
    //wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    //sizer->Add(new wxStaticText(this, wxID_ANY, "Text to change",  wxDefaultPosition, wxSize(width/2, 20)), 0, 10, wxALL);
    //sizer->Add(new wxTextCtrl(this, wxID_ANY, "also must be changed", wxDefaultPosition, wxSize(width/2,20)), 0, 10 , wxALL);

    wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "Text to change", wxDefaultPosition, wxSize(width / 2, 20));
    wxStaticText* staticText01 = new wxStaticText(this, wxID_ANY, "Text to change", wxDefaultPosition, wxSize(width / 2, 20));
    wxTextCtrl* textCtrl = new wxTextCtrl(this, wxID_ANY, "also must be changed", wxDefaultPosition, wxSize(width / 2, 20));
    wxTextCtrl* textCtrl01 = new wxTextCtrl(this, wxID_ANY, "also must be changed", wxDefaultPosition, wxSize(width / 2, 20));
    gridSizer->Add(staticText, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    gridSizer->Add(textCtrl, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    gridSizer->Add(staticText01, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    gridSizer->Add(textCtrl01, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL);
    SetSizerAndFit(gridSizer);
}
