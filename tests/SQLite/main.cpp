#include <sqlite3.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
using namespace std;

int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char* data;

    rc = sqlite3_open("test.db", &db);
    
    string str_com = "select * from company";
    char *com = new char[str_com.length() + 1];
    strcpy(com, str_com.c_str());

    sqlite3_stmt *ss;

    rc = sqlite3_prepare_v2(db, com, -1, &ss, NULL);
    
    while(sqlite3_step(ss)==SQLITE_ROW) {
        for(int i = 0; i < sqlite3_column_count(ss); i++) {
            cout << sqlite3_column_text(ss, i) << " ";
        }
        cout << endl;
    }

    sqlite3_finalize(ss);

    sqlite3_close(db);

    delete [] com;

    return 0;
}
