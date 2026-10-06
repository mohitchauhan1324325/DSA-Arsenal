# Linked List

A linked list stores values in nodes connected by links rather than in one contiguous indexed block. It supports flexible insertion and deletion when the affected node or its predecessor is already known.

## Features / Characteristics

| Feature | Description |
|---|---|
| Structure | Nodes with data and one or more pointers |
| Access | Sequential traversal; no O(1) indexing |
| Insert/delete | O(1) at a known link; finding a position costs O(n) |
| Memory | Per-node pointer overhead; nodes need not be contiguous |
| Type | Linear and mutable; size can grow dynamically |

## Visual Structure

```text
Head
 ↓
[10 | next] → [20 | next] → [30 | next] → NULL
```

## Applications

- Queues and deques.
- LRU caches when paired with a hash map and doubly linked list.
- Structures where items are frequently inserted/removed through existing node references.
- Graph adjacency lists.

## How It Works

1. Keep a head pointer (and optionally a tail pointer).
2. Traverse by following each node's `next` pointer.
3. Insert by linking a new node between neighboring nodes.
4. Delete by redirecting the predecessor link around the removed node.
5. In a doubly linked list, maintain both `prev` and `next` links.

## Problems / Limitations

- Accessing the kth element takes O(k), unlike an array's O(1) indexing.
- Each node consumes pointer memory and incurs allocation overhead.
- Pointer mistakes can lose nodes, create cycles, or leave stale links.
- Poor cache locality often makes list traversal slower than array traversal.
- Singly linked lists cannot move backward without additional state.

## Time & Space Complexity

| Operation | Complexity |
|---|---:|
| Access/search by value | O(n) |
| Insert/delete at head | O(1) |
| Insert/delete after known node (singly linked) | O(1) |
| Append with tail pointer | O(1) |
| Append without tail pointer | O(n) |
| Space for n nodes | O(n), plus link overhead |

## When to Use

- Use a linked list when the workload has frequent edits at known positions.
- Use a doubly linked list when both forward/backward traversal and constant-time removal by node are needed.

## When Not to Use

- Prefer arrays/vectors for random access, cache locality, or frequent scans.
- Prefer a deque for standard end operations unless custom node references are needed.
- Prefer a tree or hash map for fast search by key.

## Types / Variations

- Singly linked list.
- Doubly linked list.
- Circular singly or doubly linked list.
- Sentinel/head-tail node designs.

## DSA / Interview Notes

- Draw pointer changes before coding insert/delete/reversal.
- Handle empty list, one node, head/tail removal, and cycles.
- In cycle detection, Floyd's slow/fast pointers use O(1) extra space.
- Clarify whether deletion receives the node, its predecessor, or a value.



