using Core;

namespace Examples;

public record CounterIncremented();
public record CounterDecremented();

public partial class CounterAggregate : AggregateRoot
{
    public int Value { get; private set; }

    public CounterAggregate(string id)
        : base(id)
    {
    }

    public void Increment() {}
    public void Decrement() {}

    protected override void Apply(IEvent<object> @event)
    {
    }
}
