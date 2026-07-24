#pragma once

#include <zen/Event.hpp>

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace zen {

class EventDispatcher {
public:
    using Listener = std::function<void(const Event&)>;

    void subscribe(const std::string& eventName,
                   Listener listener);

    void emit(const Event& event);

private:
    std::unordered_map<std::string,
        std::vector<Listener>> m_listeners;
};

} // namespace zen
