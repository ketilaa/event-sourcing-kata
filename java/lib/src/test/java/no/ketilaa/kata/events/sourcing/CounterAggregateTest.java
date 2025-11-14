package no.ketilaa.kata.events.sourcing;

import static org.assertj.core.api.Assertions.assertThat;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class CounterAggregateTest {
    private static final String COUNTER_ID = "counter-1";

    private CounterAggregate aggregate;

    @BeforeEach
    public void setup() {
        aggregate = new CounterAggregate(COUNTER_ID);
    }

    @Test
    public void newAggregateMustBePossibleToReplay() {
        aggregate.increment();

        var replayed = new CounterAggregate(COUNTER_ID);
        replayed.replay(aggregate.uncommittedEvents());

        assertThat(aggregate.count()).isEqualTo(1);
        assertThat(replayed.count()).isEqualTo(1);
    }

    @Test
    public void newAggregateShouldHaveCountZero() {
        assertThat(aggregate.count()).isZero();
    }

    @Test
    public void incrementCommandShouldIncrementCount() {
        aggregate.increment();
        assertThat(aggregate.count()).isEqualTo(1);
    }

    @Test
    public void decrementCommandShouldDecrementCount() {
        aggregate.decrement();
        assertThat(aggregate.count()).isEqualTo(-1);
    }
}
