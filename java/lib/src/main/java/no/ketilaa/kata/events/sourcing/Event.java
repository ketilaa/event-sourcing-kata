package no.ketilaa.kata.events.sourcing;

import java.time.Instant;

public interface Event<P> {
    String aggregateId();
    Instant occurredAt();
    P payload();
}
