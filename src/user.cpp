#include "user.h"
#include <iostream>
#include <sqlite3.h>
#include <cstring>
#include <string>

using namespace std;

bool user::loggin(string u, string p) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    char* error;
    sqlite3_open("accounts.db", &db);
    int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS data  (username VARCHAR(20), password VARCHAR(20));", NULL, NULL, &error);
    if (rc != SQLITE_OK) {
        cout << "Error: " << error << endl;
    }
    string query = "SELECT * FROM data WHERE username = '";
    query += u;
    query += "';";
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const unsigned char* user = sqlite3_column_text(stmt, 0);
        const unsigned char* pass = sqlite3_column_text(stmt, 1);
        if (strcmp(reinterpret_cast<const char*>(p.c_str()), reinterpret_cast<const char*>(pass)) == 0) {
            cout << "Logged In Successfully!\n";
            return true;
        }
    }
    cout << "Incorrect Username or Password\n";
    return false;
}
