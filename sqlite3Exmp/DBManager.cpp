#include "DBManager.h"

DBManager::DBManager()
{
	int rc;

	rc = sqlite3_open("Abed", &db);
	if (rc) {
		std::cout << "Error";
	}

	if (clean_db() == SQLITE_DONE)
	{
		rc = init_table();
		if (rc != SQLITE_DONE) std::cout << "Cannot create the table";
	}

    
}

DBManager::~DBManager()
{
    sqlite3_close(db);
}

int DBManager::add_record(int id, const char* name)
{
	const char *zSql = "insert into Ahmed (id, name) values (?, ?);";
	sqlite3_stmt* stmt;
	int rc = 0;

	sqlite3_prepare_v2(db, zSql, -1, &stmt, 0);
	sqlite3_bind_int(stmt, 1, id);
	sqlite3_bind_text(stmt, 2, name, -1, NULL);
	rc = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	return rc;
}

int DBManager::clean_db()
{
	sqlite3_stmt* stmt;
	int rc = 0;
	const char* zSql = "DROP TABLE IF EXISTS Ahmed;";
	sqlite3_prepare_v2(db, zSql, -1, &stmt, 0);
	rc = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	return rc;
}

int DBManager::init_table()
{
	int rc = 0;
	sqlite3_stmt* stmt;
	const char *zSql = "CREATE TABLE if not exists Ahmed ( id INTEGER, name TEXT );";
	sqlite3_prepare_v2(db, zSql, -1, &stmt, 0);
	rc = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	return rc;
}

void DBManager::show_results()
{
    system("cls");
	sqlite3_stmt *stmt;

	const char *zSql = "select * from Ahmed;";


	sqlite3_prepare_v2(db, zSql, -1, &stmt, NULL);

	std::cout << "*************************" << std::endl;
	std::string id =  sqlite3_column_name(stmt, 0);
	std::cout << "|  " << id << "\t" << "|";
	std::string name =  sqlite3_column_name(stmt, 1);
	std::cout << "    " << name <<  "\t" "|" << std::endl;
	std::cout << "*************************" << std::endl;

	while (sqlite3_step(stmt) == SQLITE_ROW)
	{
		for (int i = 0; i < sqlite3_column_count(stmt); i++)
		{
			std::cout << "|  " << sqlite3_column_text(stmt, i);
			if ((i % 2) == 1)
            { 
				std::cout <<  "\t"  << "|" << std::endl;
                std::cout << "*************************" << std::endl;
            }
			else
				std::cout << "\t" ;
		}

	}

	/*
	sqlite3_get_table(db, zSql, &pazResult, &pnRow, &pnColumn, &pzErrmsg);

	for (int i = 0; i <= pnRow; i++)
		for (int j = 0; j < pnColumn; j++)
		{
			std::cout << pazResult[i * 2 + j];
			if ((i * 2 + j) % 2 == 1)
				std::cout << std::endl;
			else
				std::cout << "\t";
		}
		*/

}

void DBManager::new_record()
{

	int myId = 0;
	std::string ProName = "";
	const char *myName = "";

    std::cout << "Enter a new id:" << std::endl;
    std::cin >> myId;
	if (!isdigit(myId))
	{
		std::cout << "please enter a valid id" << std::endl;
		std::cin >> myId;
	}

    std::cout << "Enter a new name:" << std::endl;
    std::cin >> ProName;

    myName = ProName.c_str();
	
    add_record(myId, myName);
}


void DBManager::init_UI()
{
    bool quit = false;
	while (!quit)
	{
		std::cout << "press n to new entry, press q to exit or s to show all records" << std::endl;
		char c = 0;
		std::cin >> c;

        switch (c)
        {
        case 'q':
            quit = true;
            break;
        case 'n':
            new_record();
            break;
        case 's':
            show_results();
            break;
        default:
            std::cout << "not a valid option" << std::endl;
            break;
        }
	}

}
