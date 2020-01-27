// sqlite3Exmp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "sqlite3.h"

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
	char** pazResult;
	int pnRow = 0;
	int pnColumn = 0;
	char* pzErrmsg;

	const char *zSql = "select * from Ahmed;";

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

	

	int id = 1;
	const char* name = "Khadiga";

	rc = add_record(db, id, name);

	id = 4;
	name = "Mohamed";
	rc = add_record(db, id, name);

	id = 6;
	name = "Lobna";

	rc = add_record(db, id, name);
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");
	rc = add_record(db, 7, "Ahmed");


	show_results(db);
	sqlite3_close(db);




}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
