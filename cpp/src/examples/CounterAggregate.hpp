#pragma once
#include "../core/AggregateRoot.hpp"
#include "../core/Event.hpp"
#include "../core/Overloaded.hpp"
#include <variant>
#include <string>

struct CounterIncremented { int amount = 1; };
struct CounterDecremented { int amount = 1; };
struct CounterState { int value = 0; };

class CounterAggregate : public AggregateRoot<CounterState, std::variant<CounterIncremented, CounterDecremented>> {
public:
    using P = std::variant<CounterIncremented, CounterDecremented>;
    using E = Event<P>;

    CounterAggregate(const std::string& id);

    void increment(int amount = 1);
    void decrement(int amount = 1);

protected:
    void apply(const E& e) override;
};
