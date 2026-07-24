#include <zen/Config.hpp>

#include <fstream>

namespace zen {

Config::Config(const std::string& filename)
    : m_filename(filename) {}

bool Config::load() {
    std::ifstream file(m_filename);

    if (!file)
        return false;

    file >> m_json;
    return true;
}

bool Config::save() const {
    std::ofstream file(m_filename);

    if (!file)
        return false;

    file << m_json.dump(4);
    return true;
}

void Config::set(const std::string& key, const nlohmann::json& value) {
    m_json[key] = value;
}

std::string Config::getString(const std::string& key,
                              const std::string& defaultValue) const {
    return m_json.value(key, defaultValue);
}

int Config::getInt(const std::string& key,
                   int defaultValue) const {
    return m_json.value(key, defaultValue);
}

double Config::getDouble(const std::string& key,
                         double defaultValue) const {
    return m_json.value(key, defaultValue);
}

bool Config::getBool(const std::string& key,
                     bool defaultValue) const {
    return m_json.value(key, defaultValue);
}

} // namespace zen
