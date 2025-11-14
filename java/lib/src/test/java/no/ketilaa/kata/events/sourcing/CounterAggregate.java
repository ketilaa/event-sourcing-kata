package no.ketilaa.kata.events.sourcing;

import static java.util.Objects.isNull;
import java.util.List;

public class CounterAggregate extends AggregateRoot {

    public static CounterAggregate fromHistory(List<Event<?>> history) {
        if (isNull(history) || history.isEmpty()) {
            throw new IllegalArgumentException("history is null or empty");
        }
        var aggregateId = history.getFirst().aggregateId();
        var aggregate = new CounterAggregate(aggregateId);
        aggregate.replay(history);
        return aggregate;
    }

    public CounterAggregate(String aggregateId) {
        super(aggregateId);
    }

    public long count() {
        throw new UnsupportedOperationException();
    }

    public void increment() {
        throw new UnsupportedOperationException();
    }

    public void decrement() {
        throw new UnsupportedOperationException();
    }

    @Override
    protected void apply(Event<?> event) {

    }
}
