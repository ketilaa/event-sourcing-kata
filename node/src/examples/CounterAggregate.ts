import { AggregateRoot } from '../core/AggregateRoot'
import { Event } from '../core/Event'

export class CounterAggregate extends AggregateRoot {
  private count: number = 1

  get value(): number {
    return this.count
  }

  apply(event: Event): void {
      throw new Error('Method not implemented.')
  }

  increment(): void {
    throw new Error("Not supported!")
  }

  decrement(): void {
    throw new Error("Not supported!")
  }
}
