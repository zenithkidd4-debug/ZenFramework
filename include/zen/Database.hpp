#pragma once

#include <sqlite3.h>
#include <string>

namespace zen {

class Database {
public:
    explicit Database(const std::string& filename);
    ~Database();

    bool open();
    void close();

    bool execute(const std::string& sql);

    sqlite3* handle() const;

private:
    std::string m_filename;
    sqlite3* m_db;
};

} // namespace zen
