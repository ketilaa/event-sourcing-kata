#pragma once
#include "Event.hpp"
#include "StoredEvent.hpp"
#include <unordered_map>
#include <vector>
#include <optional>
#include <mutex>
#include <shared_mutex>

// A minimal in-memory event store. It stores StoredEvent<P> internally and returns Event<P>.
template<typename P>
class InMemoryEventStore {
public:
    using EventType = Event<P>;
    using StoredType = StoredEvent<P>;

    void appendEvents(const std::string& aggregateId, const std::vector<EventType>& newEvents, long expectedVersion) {
        std::unique_lock lock(mutex_);
        auto& stream = streams_[aggregateId]; // default constructs if not present

        long currentVersion = stream.empty() ? 0 : stream.back().version;
        if (currentVersion != expectedVersion) {
            throw std::runtime_error("Concurrency conflict: expected version " + std::to_string(expectedVersion) + " but found " + std::to_string(currentVersion));
        }

        long version = expectedVersion;
        for (auto const& e : newEvents) {
            ++version;
            stream.emplace_back(e, version);
        }
    }

    std::vector<EventType> loadEvents(const std::string& aggregateId) const {
        std::shared_lock lock(mutex_);
        auto it = streams_.find(aggregateId);
        if (it == streams_.end()) return {};
        std::vector<EventType> out;
        out.reserve(it->second.size());
        for (auto const& se : it->second) out.push_back(se.event);
        return out;
    }

    std::optional<StoredType> loadLatestStoredEvent(const std::string& aggregateId) const {
        std::shared_lock lock(mutex_);
        auto it = streams_.find(aggregateId);
        if (it == streams_.end() || it->second.empty()) return std::nullopt;
        return it->second.back();
    }

private:
    mutable std::shared_mutex mutex_;
    std::unordered_map<std::string, std::vector<StoredType>> streams_;
};
