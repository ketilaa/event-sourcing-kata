using Examples;
using Xunit;

public class CounterAggregateTests
{
    [Fact]
    public void Increment_ShouldIncreaseValue_AndProduceEvent()
    {
        var agg = new CounterAggregate("counter-1");

        agg.Increment();
        agg.Increment();
        agg.Decrement();

        Assert.Equal(1, agg.Value);
        Assert.Equal(3, agg.GetUncommittedEvents().Count);
    }

    [Fact]
    public void Replay_ShouldRebuildState()
    {
        var agg = new CounterAggregate("counter-1");

        // TODO: provide history and replay it

        Assert.Equal(2, agg.Value);
    }
}
