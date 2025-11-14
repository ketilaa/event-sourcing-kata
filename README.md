# 🧩 Event Sourcing Kata

> Build a minimal **event sourcing framework** from scratch using **TDD**.

This kata is a hands-on exercise in understanding the core mechanics of **event sourcing** —  
how domain state evolves by replaying **immutable events** rather than persisting object state directly.

You’ll implement a tiny, language-idiomatic framework around four concepts:
- **Event** – something that *happened*
- **AggregateRoot** – rebuilds state from events
- **EventStore** – persists and retrieves event streams
- *(Optional)* **Snapshot** – captures state at a point in time

---

## 🧭 Goals

- Understand how **state = replay(history of events)**  
- Practice **test-driven development (TDD)** to design from behavior first  
- Keep everything **pure and simple** — no external dependencies or frameworks  
- Produce a working system that can:
  1. Raise new events  
  2. Apply them to change state  
  3. Persist them  
  4. Replay them to rebuild state  

---

## Java
### Prerequisites
- Java 21
- Gradle

### Build and run tests
```shell
cd java
./gradlew test
```
## .Net
### Prerequisites
- .Net9+

### Build and run tests
```shell
cd dotnet
dotnet test
```

## C++

### Prerequisites
- cmake
- C++ 20

### Initialize, build and run tests
```shell
cd cpp
mkdir build
cd build
cmake ..
cmake --build .
ctest --output-on-failure
```

## Node.js

### Prerequisites
- Node.js ≥ 18
- npm
- Basic knowledge of TypeScript

### Initialize and build
```shell
cd node
npm install
npm test
```