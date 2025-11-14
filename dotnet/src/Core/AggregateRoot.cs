namespace Core;

public abstract class AggregateRoot
{
    public string AggregateId { get; }

    private readonly List<IEvent<object>> _uncommitted = [];

    protected AggregateRoot(string aggregateId)
    {
        AggregateId = aggregateId;
    }

    protected abstract void Apply(IEvent<object> @event);

    protected void Raise(IEvent<object> @event)
    {
        Apply(@event);
        _uncommitted.Add(@event);
    }

    public IReadOnlyList<IEvent<object>> GetUncommittedEvents() => _uncommitted.AsReadOnly();

    public void Replay(IEnumerable<IEvent<object>> history)
    {
        foreach (var e in history)
            Apply(e);
    }
}
