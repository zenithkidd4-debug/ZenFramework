#include <zen/HttpClient.hpp>

#include <iostream>

int main() {
    zen::HttpClient client;

    std::string response =
        client.get("https://api.github.com");

    std::cout << response << std::endl;

    return 0;
}
