// sqlite3Exmp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "sqlite3.h"
#include <string>

int clean_db(sqlite3* db)
{
	sqlite3_stmt* stmt;
	int rc = 0;
	const char* zSql = "DROP TABLE IF EXISTS Ahmed;";
	sqlite3_prepare_v2(db, zSql, -1, &stmt, 0);
	rc = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	return rc;
}

int add_record(sqlite3 *db, int id, const char* name)
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

int init_db(sqlite3* db)
{
	int rc = 0;
	sqlite3_stmt* stmt;
	const char *zSql = "CREATE TABLE if not exists Ahmed ( id INTEGER, name TEXT );";
	sqlite3_prepare_v2(db, zSql, -1, &stmt, 0);
	rc = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	return rc;

}

void show_results(sqlite3* db)
{
	sqlite3_stmt *stmt;

	const char *zSql = "select * from Ahmed;";


	sqlite3_prepare_v2(db, zSql, -1, &stmt, NULL);

	std::string id =  sqlite3_column_name(stmt, 0);
	std::cout << id << "\t" << "|";
	std::string name =  sqlite3_column_name(stmt, 1);
	std::cout << name << std::endl;
	std::cout << "-----------------------" << std::endl;

	while (sqlite3_step(stmt) == SQLITE_ROW)
	{
		for (int i = 0; i < sqlite3_column_count(stmt); i++)
		{
			std::cout << sqlite3_column_text(stmt, i);
			if ((i % 2) == 1)
				std::cout << std::endl;
			else
				std::cout << "\t"<< "|";
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

int main()
{
	sqlite3* db;
	int rc;

	rc = sqlite3_open("Abed", &db);
	if (rc) {
		printf("Error");
	}

	if (clean_db(db) == SQLITE_DONE)
	{
		rc = init_db(db);
		if (rc != SQLITE_DONE) std::cout << "Cannot initialize the database";
	}

	
	int myId = 0;
	std::string ProName;
	const char *myName = "";
	show_results(db);
	while (1)
	{
		std::cout << "Enter a new id:" << std::endl;
		std::cin >> myId;
		std::cout << "Enter a new name:" << std::endl;
		std::cin >> ProName;
		myName = ProName.c_str();
		add_record(db, myId, myName);
		show_results(db);
		std::cout << "press n to new entry, press q to exit" << std::endl;
		char c;
		std::cin >> c;
	
		if (c == 'q')
			break;
		if (c == 'n')
			continue;
	}




	sqlite3_close(db);


	std::cin.get();




}

