import { describe, it, expect } from 'vitest'
import { CounterAggregate } from '../../src/examples/CounterAggregate'

describe('CounterAggregate', () => {
  it('should replay from history', () => {
    const aggregateId = "counter-1"
    const counter = new CounterAggregate(aggregateId)
    counter.increment()

    const replayed = new CounterAggregate(aggregateId)
    replayed.replay(counter.uncommittedEvents)

    expect(replayed.value).toBe(counter.value)
  })
})

describe('CounterAggregate', () => {
  it('should increment', () => {
    const aggregateId = "counter-1"
    const counter = new CounterAggregate(aggregateId)

    counter.increment()

    expect(counter.value).toBe(1)
  })
})

describe('CounterAggregate', () => {
  it('should decrement', () => {
    const aggregateId = "counter-1"
    const counter = new CounterAggregate(aggregateId)

    counter.decrement()

    expect(counter.value).toBe(-1)
  })
})
