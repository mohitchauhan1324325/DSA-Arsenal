# Queue

A queue is a first-in, first-out (FIFO) collection: new items enter at the rear and the oldest item leaves from the front. It is useful whenever work must be processed in arrival order.

## Features / Characteristics

| Feature | Description |
|---|---|
| Order | FIFO |
| Operations | Enqueue at rear, dequeue at front, inspect front |
| Typical operation cost | O(1) with a suitable implementation |
| Memory | Dynamic linked storage or fixed/circular buffer |
| Type | Linear collection; mutable |

## Visual Structure

```text
dequeue                                      enqueue
   ↓                                            ↓
front → [first] → [second] → [newest] ← rear
```

## Applications

- BFS and level-order tree traversal.
- Request queues, event loops, and producer-consumer pipelines.
- Print spooling, job scheduling, and network packet buffering.
- Rate-limited work processing.

## How It Works

1. Enqueue appends an item at the rear.
2. Dequeue removes and returns the item at the front.
3. Peek reads the front without removing it.
4. A circular array advances head/tail indices modulo capacity; a linked queue updates endpoint links.
5. A bounded queue reports full or applies back-pressure when capacity is reached.

## Problems / Limitations

- A bounded queue can overflow unless the producer is blocked, rejected, or data is dropped intentionally.
- FIFO cannot prioritize urgent work or efficiently access arbitrary items.
- Circular buffers require careful full/empty bookkeeping.
- Concurrent queues need synchronization or a safe lock-free design.

## Time & Space Complexity

| Operation | Linked queue / circular buffer |
|---|---:|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek front | O(1) |
| Search arbitrary value | O(n) |
| Space for n elements | O(n) |

## When to Use

- Use a queue for arrival-order processing and BFS.
- Use a deque when both ends need efficient insertion/removal.
- Use a bounded queue to cap memory and communicate back-pressure.

## When Not to Use

- Use a priority queue when highest priority must be served first.
- Use a stack when newest work should be processed first.
- Use an indexed collection when arbitrary access is central.

## Types / Variations

- Simple FIFO queue.
- Circular queue.
- Deque (double-ended queue).
- Priority queue (ordered by priority, not strictly FIFO).

## DSA / Interview Notes

- Mark graph vertices visited when enqueued to avoid duplicate work.
- Test empty dequeue, one element, wrap-around, and full capacity.
- BFS finds shortest edge-count paths in unweighted graphs.


