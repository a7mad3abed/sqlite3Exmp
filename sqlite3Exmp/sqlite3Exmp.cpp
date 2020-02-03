// sqlite3Exmp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "DBManager.h"



int main()
{

    init_db();
	
    init_UI();



	sqlite3_close(db);


	std::cin.get();




}

