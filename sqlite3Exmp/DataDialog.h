#pragma once
#include "wx/wx.h"
#include "DBManager.h"
#include "wx/listctrl.h"
#include "wx/dataview.h"


class DataDialog : public wxDialog
{
public:
    DataDialog(wxWindow *parent, const wxString& title, const wxSize &size, DBManager *dBM);

private:
    std::vector<Result> results;
    

};

