#include "MyApp.h"
#include "MyFrame.h"

namespace ExmpApp {

    wxIMPLEMENT_APP(MyApp);

    bool MyApp::OnInit()
    {
        MyFrame* frame = new MyFrame("wx plus sqlite", wxPoint(100, 100), wxSize(800, 600));
        frame->Show(true);
        return true;

    }
}
