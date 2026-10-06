# Heap / Priority Queue

A heap is a complete binary tree that maintains a parent-child ordering rule. A priority queue exposes the item with highest or lowest priority; a binary heap is a common efficient implementation.

## Features / Characteristics

| Feature | Description |
|---|---|
| Shape | Complete binary tree, commonly stored in an array |
| Order | Min-heap parent ≤ children; max-heap parent ≥ children |
| Peek | O(1) |
| Insert/remove root | O(log n) |
| Arbitrary search | O(n) |
| Type | Mutable priority structure |

## Visual Structure

```text
             2
           /   \
          5     7
         / \   /
        9  11 8

Array: [2, 5, 7, 9, 11, 8]
```

## Applications

- CPU/task scheduling and event simulation.
- Top-K selection and merging sorted streams.
- Dijkstra's algorithm and best-first search.
- Maintaining running medians with a min-heap and max-heap.

## How It Works

1. Store nodes in level order in an array.
2. Insert by appending at the end, then sift upward until heap order holds.
3. Remove the root by replacing it with the last element, then sift downward.
4. Read the root to obtain the current minimum or maximum.
5. Repeat extraction when elements must be processed by priority.

## Problems / Limitations

- Heap order is partial, not a full sort.
- Searching for an arbitrary key takes O(n).
- Updating an arbitrary priority efficiently requires tracking the element's index.
- Equal priorities may need an explicit tie-breaker.
- A heap may be less suitable than a balanced tree when arbitrary ordered queries are required.

## Time & Space Complexity

| Operation | Binary heap |
|---|---:|
| Peek min/max | O(1) |
| Insert | O(log n) |
| Remove root | O(log n) |
| Build heap from n values | O(n) |
| Search arbitrary value | O(n) |
| Space | O(n) |

## When to Use

- Use a priority queue when the next item is repeatedly selected by priority.
- Use a heap for top-K, scheduling, and graph algorithms with repeated minimum extraction.

## When Not to Use

- Use a sorted array for small, mostly static data needing ordered iteration.
- Use a balanced tree when arbitrary lookup, deletion, and range traversal are all needed.
- Do not use a heap for fast search of arbitrary values.

## Types / Variations

- Min-heap and max-heap.
- Binary, d-ary, binomial, Fibonacci, and pairing heaps.
- Double-ended priority queues; two-heap median structures.

## DSA / Interview Notes

- In a zero-indexed binary heap, parent is `(i-1)/2`; children are `2i+1` and `2i+2`.
- Decide min-heap versus max-heap based on the desired root.
- For top-K, clarify whether the heap stores K candidates or all values.
- Lazy deletion is common when priorities change but direct updates are inconvenient.
