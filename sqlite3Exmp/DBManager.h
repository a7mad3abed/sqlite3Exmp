#pragma once
#include <iostream>
#include "sqlite3.h"
#include <vector>
#include <string>

struct Result;

class DBManager
{
public:
    DBManager();
    ~DBManager();
    int clean_db();
    int add_record( const char *id, const char* name);
    int init_table();
    void show_results();
    void new_record();
    void init_UI();
    std::vector<Result> retrieveResults();

private:
    sqlite3 *db;
    
};

struct Result
{
    std::string id ;
    std::string name ;
};
