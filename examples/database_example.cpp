#include <zen/Database.hpp>

#include <iostream>

int main() {
    zen::Database db("zenframework.db");

    if (!db.open()) {
        return 1;
    }

    db.execute(
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT,"
        "age INTEGER);"
    );

    db.execute(
        "INSERT INTO users(name, age) "
        "VALUES('Zenith', 20);"
    );

    std::cout << "Database created successfully!" << std::endl;

    db.close();

    return 0;
}
