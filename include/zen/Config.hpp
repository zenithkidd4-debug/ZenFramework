#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace zen {

class Config {
public:
    explicit Config(const std::string& filename);

    bool load();
    bool save() const;

    void set(const std::string& key, const nlohmann::json& value);

    std::string getString(const std::string& key,
                          const std::string& defaultValue = "") const;

    int getInt(const std::string& key,
               int defaultValue = 0) const;

    double getDouble(const std::string& key,
                     double defaultValue = 0.0) const;

    bool getBool(const std::string& key,
                 bool defaultValue = false) const;

private:
    std::string m_filename;
    nlohmann::json m_json;
};

} // namespace zen
