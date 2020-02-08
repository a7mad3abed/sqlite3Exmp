#include "MyFrame.h"


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    wxPanel* panel01 = new wxPanel(this, wxID_ANY);
    wxStaticText* text01 = new wxStaticText(panel01, wxID_ANY, "Text to change", );
    wxTextCtrl* textCtl = new wxTextCtrl(panel01, wxID_ANY, "also must be changed");

}
