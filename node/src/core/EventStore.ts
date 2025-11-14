import type { Event } from './Event'

export interface EventStore {
  appendEvents(aggregateId: string, newEvents: Event[]): void
  loadEvents(aggregateId: string): Event[]
}