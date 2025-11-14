export interface Event<P = any> {
  eventId: string
  occurredAt: Date
  aggregateId: string
  payload: P
}

export const createEvent = <P>(aggregateId: string, payload: P): Event<P> => ({
  eventId: crypto.randomUUID(),
  occurredAt: new Date(),
  aggregateId,
  payload
})
