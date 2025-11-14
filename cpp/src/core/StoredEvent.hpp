#pragma once
#include "Event.hpp"
#include <chrono>

template<typename P>
struct StoredEvent {
    Event<P> event;
    long version;
    std::chrono::system_clock::time_point storedAt;

    StoredEvent(Event<P> e, long v)
        : event(std::move(e)), version(v), storedAt(std::chrono::system_clock::now()) {}
};
