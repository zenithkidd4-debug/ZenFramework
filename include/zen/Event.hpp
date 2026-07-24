#pragma once

#include <string>

namespace zen {

class Event {
public:
    explicit Event(const std::string& name)
        : m_name(name)
    {
    }

    const std::string& name() const
    {
        return m_name;
    }

private:
    std::string m_name;
};

} // namespace zen
