#include "CounterAggregate.hpp"

CounterAggregate::CounterAggregate(const std::string& id)
    : AggregateRoot(id, CounterState{}) {}

void CounterAggregate::increment(int amount) {
    raise(E(id_, CounterIncremented{amount}));
}

void CounterAggregate::decrement(int amount) {
    raise(E(id_, CounterDecremented{amount}));
}

void CounterAggregate::apply(const E& e) {
    std::visit(overloaded{
        [this](const CounterIncremented& inc) { state_.value += inc.amount; },
        [this](const CounterDecremented& dec) { state_.value -= dec.amount; }
    }, e.payload);
}
