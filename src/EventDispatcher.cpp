#include <zen/EventDispatcher.hpp>

namespace zen {

void EventDispatcher::subscribe(const std::string& eventName,
                                Listener listener)
{
    m_listeners[eventName].push_back(std::move(listener));
}

void EventDispatcher::emit(const Event& event)
{
    auto it = m_listeners.find(event.name());

    if (it == m_listeners.end())
    {
        return;
    }

    for (const auto& listener : it->second)
    {
        listener(event);
    }
}

} // namespace zen
