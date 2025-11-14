#pragma once
#include <string>
#include <chrono>
#include <uuid/uuid.h> // optional, see note below
#include <random>
#include <sstream>

// Simple EventMetadata: event id + when it occurred
struct EventMetadata {
    std::string eventId;
    std::chrono::system_clock::time_point occurredAt;

    static std::string makeUuid() {
        // portable fallback for a unique-ish string without external libs
        // uses timestamp + random
        auto now = std::chrono::system_clock::now().time_since_epoch().count();
        static std::mt19937_64 rng{std::random_device{}()};
        std::uniform_int_distribution<uint64_t> dist;
        std::ostringstream ss;
        ss << std::hex << now << "-" << dist(rng);
        return ss.str();
    }

    static EventMetadata now() {
        return EventMetadata{ makeUuid(), std::chrono::system_clock::now() };
    }
};

// Generic Event<P> (payload should be a POD-like/aggregate-defined type)
template<typename P>
struct Event {
    std::string aggregateId;
    P payload;
    EventMetadata metadata;

    Event() = default;
    Event(std::string aggId, P p, EventMetadata m = EventMetadata::now())
        : aggregateId(std::move(aggId)), payload(std::move(p)), metadata(std::move(m)) {}
};
