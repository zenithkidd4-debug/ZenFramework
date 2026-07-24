#include <zen/Database.hpp>

#include <iostream>

namespace zen {

Database::Database(const std::string& filename)
    : m_filename(filename), m_db(nullptr) {
}

Database::~Database() {
    close();
}

bool Database::open() {
    if (sqlite3_open(m_filename.c_str(), &m_db) != SQLITE_OK) {
        std::cerr << "SQLite Error: "
                  << sqlite3_errmsg(m_db)
                  << std::endl;
        return false;
    }

    return true;
}

void Database::close() {
    if (m_db) {
        sqlite3_close(m_db);
        m_db = nullptr;
    }
}

bool Database::execute(const std::string& sql) {
    char* error = nullptr;

    int rc = sqlite3_exec(
        m_db,
        sql.c_str(),
        nullptr,
        nullptr,
        &error
    );

    if (rc != SQLITE_OK) {
        std::cerr << "SQLite Error: "
                  << error
                  << std::endl;

        sqlite3_free(error);
        return false;
    }

    return true;
}

sqlite3* Database::handle() const {
    return m_db;
}

} // namespace zen
