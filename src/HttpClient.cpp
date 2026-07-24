#include <zen/HttpClient.hpp>

#include <curl/curl.h>
#include <iostream>
#include <string>

namespace zen {

static size_t WriteCallback(void* contents,
                            size_t size,
                            size_t nmemb,
                            void* userp)
{
    size_t totalSize = size * nmemb;

    static_cast<std::string*>(userp)->append(
        static_cast<char*>(contents),
        totalSize
    );

    return totalSize;
}

HttpClient::HttpClient()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

HttpClient::~HttpClient()
{
    curl_global_cleanup();
}

std::string HttpClient::get(const std::string& url)
{
    CURL* curl = curl_easy_init();

    if (!curl)
    {
        return "";
    }

    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Required by GitHub
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "ZenFramework/0.7");

    // Follow redirects
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // HTTPS verification
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);

    // Timeout (30 seconds)
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);

    CURLcode result = curl_easy_perform(curl);

    if (result != CURLE_OK)
    {
        std::cerr << "CURL Error: "
                  << curl_easy_strerror(result)
                  << std::endl;
    }
    else
    {
        long httpCode = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

        if (httpCode != 200)
        {
            std::cerr << "HTTP Error: "
                      << httpCode
                      << std::endl;
        }
    }

    curl_easy_cleanup(curl);

    return response;
}

} // namespace zen
