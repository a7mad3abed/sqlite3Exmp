#include "DataDialog.h"


DataDialog::DataDialog(wxWindow* parent,  const wxString& title, const wxSize &size, DBManager *dBM)
    :wxDialog(parent, wxID_ANY, title, wxDefaultPosition, size, wxDEFAULT_DIALOG_STYLE, "results" )
{

    wxDataViewListCtrl* list = new wxDataViewListCtrl(this, wxID_ANY);
    list->AppendTextColumn("id");
    list->AppendTextColumn("name");

    wxVector<wxVariant> data;

    results = dBM->retrieveResults();

    for (int i = 0; i < results.size(); i++)
    {
        data.push_back(results[i].id);
        data.push_back(results[i].name);

        list->AppendItem(data);

        data.clear();
    }




}


