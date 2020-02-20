// sqlite3Exmp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "MyApp.h"



int main()
{

    MyApp *myApp = new MyApp();
    myApp->OnInit();
    //DBManager* dbman = new DBManager();
    //dbman->init_UI();

    //delete dbman;

    delete myApp;


}

