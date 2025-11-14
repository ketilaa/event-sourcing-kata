#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "../src/core/Event.hpp"
#include "../src/core/EventStore.hpp"
#include "../src/examples/CounterAggregate.hpp"

// Use the simple CounterAggregate implementation from examples
// (A minimal test that focuses on replay and append)

TEST_CASE("CounterAggregate increments and produces events") {
    CounterAggregate agg("counter-1");
    agg.increment();
    agg.increment();
    agg.decrement();

    REQUIRE(agg.state().value == 1);
    REQUIRE(agg.uncommittedEvents().size() == 3);
}

TEST_CASE("InMemoryEventStore append/load and replay") {
    InMemoryEventStore<std::variant<CounterIncremented, CounterDecremented>> store;
    CounterAggregate agg("counter-2");
    agg.increment();
    agg.increment();

    auto events = agg.uncommittedEvents();
    store.appendEvents(agg.id(), events, 0);

    auto history = store.loadEvents(agg.id());

    CounterAggregate loaded("counter-2");
    loaded.replay(history);

    REQUIRE(loaded.state().value == 2);
}
