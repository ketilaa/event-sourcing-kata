package no.ketilaa.kata.events.sourcing;

import java.util.List;

public interface EventStore {

    void appendEvents(String aggregateId, List<Event<?>> newEvents);

    List<Event<?>> loadEvents(String aggregateId);
}
