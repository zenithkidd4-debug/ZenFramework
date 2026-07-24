#pragma once

#include <string>

namespace zen {

class HttpClient {
public:
    HttpClient();
    ~HttpClient();

    std::string get(const std::string& url);
};

} // namespace zen
