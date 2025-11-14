namespace Core;

public interface IEvent<out TPayload>
{
    string AggregateId { get; }
    Guid EventId { get; }
    DateTime OccurredAt { get; }
    TPayload Payload { get; }
}
