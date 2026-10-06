# Advanced Data Structures

The **Advanced** folder is intended for specialized structures that support operations beyond basic arrays, lists, maps, and trees. Common DSA examples include segment trees, Fenwick trees, and disjoint-set union; select one based on the exact updates and queries required.

## Features / Characteristics

| Structure | Main purpose | Typical operation |
|---|---|---|
| Segment tree | Range query with point/range updates | O(log n) |
| Fenwick tree (BIT) | Prefix aggregates with point updates | O(log n) |
| DSU / Union-Find | Connectivity under component merges | Near O(1) amortized |

These are mutable and usually require O(n) storage; their behavior depends on the operation algebra and implementation.

## Visual Structure

```text
Segment tree over [0..7]       DSU components
          [0..7]                {0,1}  {2,3}  {4}
         /      \                   union(1,2)
      [0..3]   [4..7]             {0,1,2,3} {4}

Fenwick tree stores partial prefix ranges in an indexed array.
```

## Applications

- Segment/Fenwick trees: range sums, minima, frequencies, and online updates.
- DSU: connectivity queries, Kruskal's minimum spanning tree, and grouping.
- Other specialized trees: interval, order-statistic, and range-query problems.

## How It Works

1. Identify the exact query and update operations.
2. Choose a structure whose stored summary can be combined or updated correctly.
3. Build/preprocess the structure from the initial values.
4. Apply updates while maintaining the invariant.
5. Query the relevant node/index/representative and combine partial answers if needed.

For DSU, `find` returns a component representative and `union` merges two representatives; path compression and union by size/rank improve performance.

## Problems / Limitations

- Specialized implementations are easier to get wrong than simple scans.
- Segment trees require careful interval boundaries and correct merge/identity logic.
- Fenwick trees do not support every arbitrary range operation/update combination.
- DSU supports merging components but not undoing/splitting arbitrary unions without extra techniques.
- Advanced structures may be unnecessary overhead when a simpler O(n) scan meets constraints.

## Time & Space Complexity

| Structure / operation | Time | Space |
|---|---:|---:|
| Segment tree build | O(n) | O(n) |
| Segment tree point update / range query | O(log n) | O(n) |
| Fenwick point update / prefix query | O(log n) | O(n) |
| DSU find/union, path compression + union by size | O(α(n)) amortized | O(n) |

Bounds are for common implementations and supported operations; lazy propagation or persistence changes constants/storage details.

## When to Use

- Use a segment tree when range queries and updates must both be efficient.
- Use a Fenwick tree for suitable prefix aggregates with simpler implementation.
- Use DSU for incremental connectivity where components only merge.

## When Not to Use

- Use prefix sums when the array is static and only range sums are needed.
- Use BFS/DFS for a one-time graph connectivity pass.
- Avoid DSU if deletions/splits are central to the workload.

## Types / Variations

- Segment tree, lazy segment tree, persistent segment tree.
- Fenwick tree / Binary Indexed Tree.
- DSU with path compression and union by rank/size.
- Sparse table and range-query structures for static input.

## DSA / Interview Notes

- Match the structure to the exact update/query requirements before coding.
- Define interval conventions (`[l, r]` or `[l, r)`) consistently.
- For DSU, compare representatives, not raw node IDs.
- Check whether values/aggregates need 64-bit storage.
