namespace Core;

public interface IEventStore
{
    void AppendEvents(string aggregateId, IEnumerable<IEvent<object>> events);

    IReadOnlyList<IEvent<object>> LoadEvents(string aggregateId);
}
