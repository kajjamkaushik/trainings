#include <sqlite3.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class DatabaseConnector {
private:
    sqlite3* db;

public:
    DatabaseConnector(const std::string& db_path) {
        int rc = sqlite3_open(db_path.c_str(), &db);
        if (rc) {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }
        else {
            // Create table if it doesn't exist
            const char* create_table_sql =
                "CREATE TABLE IF NOT EXISTS elevator_events ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "timestamp INTEGER NOT NULL,"
                "event_type TEXT NOT NULL,"
                "value INTEGER);";

            char* error_message = nullptr;
            rc = sqlite3_exec(db, create_table_sql, nullptr, nullptr, &error_message);

            if (rc != SQLITE_OK) {
                std::cerr << "SQL error: " << error_message << std::endl;
                sqlite3_free(error_message);
            }
        }
    }

    ~DatabaseConnector() {
        sqlite3_close(db);
    }

    void save_events(const std::vector<std::tuple<time_t, std::string, int>>& events) {
        sqlite3_stmt* stmt;
        const char* insert_sql = "INSERT INTO elevator_events (timestamp, event_type, value) VALUES (?, ?, ?)";

        int rc = sqlite3_prepare_v2(db, insert_sql, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
            return;
        }

        // Begin transaction for faster inserts
        sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);

        for (const auto& event : events) {
            sqlite3_bind_int64(stmt, 1, std::get<0>(event));
            sqlite3_bind_text(stmt, 2, std::get<1>(event).c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 3, std::get<2>(event));

            rc = sqlite3_step(stmt);
            if (rc != SQLITE_DONE) {
                std::cerr << "Failed to insert data: " << sqlite3_errmsg(db) << std::endl;
            }

            sqlite3_reset(stmt);
        }

        // Commit transaction
        sqlite3_exec(db, "COMMIT", nullptr, nullptr, nullptr);
        sqlite3_finalize(stmt);
    }
};