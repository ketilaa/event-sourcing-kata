import { Event } from './Event'

export abstract class AggregateRoot {
  private readonly _uncommittedEvents: Event[] = []
  protected _aggregateId!: string

  constructor(aggregateId: string) {
    this._aggregateId = aggregateId
  }

  get aggregateId(): string {
    return this._aggregateId
  }

  get uncommittedEvents() : Event[] {
    return this._uncommittedEvents
  }

  protected raise(event: Event): void {
    this.apply(event)
    this._uncommittedEvents.push(event)
  }

  replay(history: Event[]): void {
    history.forEach(e => this.apply(e))
  }

  abstract apply(event: Event): void
}