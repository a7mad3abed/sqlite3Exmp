#pragma once
#include <iostream>
#include "sqlite3.h"

class DBManager
{
public:
    DBManager();
    ~DBManager();
    int clean_db();
    int add_record(int id, const char* name);
    int init_table();
    void show_results();
    void new_record();
    void init_UI();

private:
    sqlite3* db;
};

