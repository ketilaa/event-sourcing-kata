#pragma once
#include "Event.hpp"
#include <vector>
#include <stdexcept>

// AggregateRoot with typed state S and event payload type P
template<typename S, typename P>
class AggregateRoot {
public:
    using EventType = Event<P>;

    AggregateRoot(std::string id, S initialState)
      : id_(std::move(id)), state_(std::move(initialState)), version_(0) {}

    virtual ~AggregateRoot() = default;

    const std::string& id() const { return id_; }
    long version() const { return version_; }
    const S& state() const { return state_; }

    std::vector<EventType> uncommittedEvents() const { return uncommitted_; }

    // replay history (used when loading from store)
    void replay(const std::vector<EventType>& history) {
        for (auto const& e : history) {
            apply(e);
            ++version_;
        }
    }

protected:
    // raise a new event (applies and marks uncommitted)
    void raise(const EventType& e) {
        apply(e);
        uncommitted_.push_back(e);
    }

    // when store persists events, call this to clear uncommitted and update version
    void markCommitted(long newVersion) {
        uncommitted_.clear();
        version_ = newVersion;
    }

    // concrete aggregates implement apply logic
    virtual void apply(const EventType& e) = 0;

    std::string id_;
    S state_;
    long version_;
    std::vector<EventType> uncommitted_;
};
