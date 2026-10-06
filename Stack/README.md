# Stack

A stack is a last-in, first-out (LIFO) collection. New items are pushed onto the top, and the most recently added item is the first one removed.

## Features / Characteristics

| Feature | Description |
|---|---|
| Order | LIFO |
| Access | Only the top item is directly available |
| Operations | Push, pop, peek |
| Typical operation cost | O(1) |
| Implementation | Array/vector or linked nodes |
| Type | Linear and mutable |

## Visual Structure

```text
       TOP
        ↓
     +------+
     |  C   |  last in, first out
     +------+
     |  B   |
     +------+
     |  A   |
     +------+
```

## Applications

- Function calls and recursion.
- Expression parsing, bracket matching, and undo histories.
- DFS and backtracking.
- Monotonic-stack problems such as next-greater-element and histogram area.

## How It Works

1. `push(x)` places `x` at the top.
2. `peek()` returns the top without removing it.
3. `pop()` removes and returns the top.
4. Check for an empty stack before pop/peek when the API does not handle emptiness.
5. For monotonic-stack algorithms, remove elements while a chosen ordering condition is violated.

## Problems / Limitations

- Older elements cannot be accessed directly.
- Popping an empty stack is invalid unless guarded.
- Recursion and unbounded explicit stacks can exhaust memory.
- A stack cannot provide FIFO fairness or priority ordering.

## Time & Space Complexity

| Operation | Complexity |
|---|---:|
| Push | O(1) amortized for dynamic array; O(1) linked |
| Pop / peek | O(1) |
| Search arbitrary item | O(n) |
| Space for n elements | O(n) |

## When to Use

- Use a stack for nested structure, undo, DFS, or reverse-order processing.
- Use a monotonic stack when each value is pushed and popped at most once to answer next/previous greater/smaller queries.

## When Not to Use

- Use a queue for arrival-order processing.
- Use a heap for repeated minimum/maximum priority retrieval.
- Use an array or map when arbitrary access/search is required.

## Types / Variations

- Array-backed and linked stacks.
- Monotonic increasing/decreasing stack.
- Call stack and explicit algorithm stack.
- Bounded stack.

## DSA / Interview Notes

- For valid-parentheses problems, push expected closers or opening symbols consistently.
- In monotonic-stack problems, decide strictly `<` versus `<=` based on duplicate handling.
- Test empty input, all increasing/decreasing values, and duplicates.


