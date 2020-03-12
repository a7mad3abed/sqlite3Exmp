#include "DataDialog.h"

namespace ExmpApp {

    DataDialog::DataDialog(wxWindow* parent, const wxString& title, const wxSize& size, DBManager* dBM)
        :wxDialog(parent, wxID_ANY, title, wxDefaultPosition, size, wxDEFAULT_DIALOG_STYLE, "results")
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

        this->Bind(wxEVT_CLOSE_WINDOW, &DataDialog::OnClose, this);




    }

    DataDialog::~DataDialog()
    {
    }

    void DataDialog::OnClose(wxCloseEvent& event)
    {
        Destroy();
    }

    /*
    BEGIN_EVENT_TABLE(DataDialog, wxDialog)
        EVT_CLOSE(DataDialog::OnClose)
    END_EVENT_TABLE()
    */
}
