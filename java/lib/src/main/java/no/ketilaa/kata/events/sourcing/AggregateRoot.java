package no.ketilaa.kata.events.sourcing;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public abstract class AggregateRoot {
    private final String aggregateId;
    private final List<Event<?>> uncommittedEvents =  new ArrayList<>();

    public AggregateRoot(String aggregateId) {
        this.aggregateId = aggregateId;
    }

    public String aggregateId() {
        return this.aggregateId;
    }

    public List<Event<?>> uncommittedEvents() {
        return Collections.unmodifiableList(uncommittedEvents);
    }

    protected void raise(Event<?> event) {
        apply(event);
        uncommittedEvents.add(event);
    }

    public void replay(List<Event<?>> history) {
        history.forEach(this::apply);
    }

    protected abstract void apply(Event<?> event);
}
