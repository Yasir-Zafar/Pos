#include<iostream>
#include<string>
#include<sqlite3.h>
using namespace std;

void findItemName(string nameitem, const char* filename)
{

	sqlite3* db;
	sqlite3_stmt* stmt;
	string query = "SELECT * FROM products WHERE Name = ";
	query = query + "'" + nameitem + "'";
	query = query + ";";
	const char* sql = query.c_str();
	cout << sql;

	int rc = sqlite3_open(filename, &db);
	if (rc != SQLITE_OK)
	{
		cout << "Cannot open database: " << sqlite3_errmsg(db) << endl;
	}

	rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK)
	{
		cout << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}

	cout << endl;

	while (sqlite3_step(stmt) == SQLITE_ROW)
	{
		cout << sqlite3_column_text(stmt, 0) << " ";
		cout << sqlite3_column_text(stmt, 1) << " ";
		cout << sqlite3_column_text(stmt, 2) << " ";
		cout << sqlite3_column_text(stmt, 3) << " ";
		cout << sqlite3_column_text(stmt, 4) << " ";
		cout << sqlite3_column_text(stmt, 5) << " ";
		cout << sqlite3_column_text(stmt, 6) << " ";
		cout << sqlite3_column_text(stmt, 7) << " ";
		cout << endl;

	}


	sqlite3_close(db);
}



int main()
{
	const char* filename = "C:\\Users\\HP\\Desktop\\products (1).db";
	string nameitem = "Bread";
	findItemName(nameitem, filename);
}