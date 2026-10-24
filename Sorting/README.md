# Sorting and Ordering Algorithms

Sorting arranges elements by a comparison or key. The files here apply ordering to count inversions, group even and odd values in sorted order, and compute pairwise Manhattan-distance sums efficiently after sorting coordinate values.

## Features / Characteristics

| Feature | Description |
|---|---|
| Input/output | Reorders values or uses sorted order to simplify a calculation |
| Ordering | Must define a consistent comparison rule |
| Stability | Depends on the chosen sorting algorithm; the parity comparator here does not promise stability |
| Mutation | The inversion and parity routines sort/mutate their input |
| Typical comparison sort | O(n log n) time |
| Trade-off | Sorting can make later scans simpler but costs time and possibly memory |

## Visual Structure

```text
Count inversions (merge):
[2, 4] + [1, 3, 5]
       compare heads
       1 precedes 2, 4 -> count both cross inversions
       merge -> [1, 2, 3, 4, 5]

Even/odd ordering:
[12, 45, 8, 3] -> [8, 12 | 3, 45]
                   evens   odds (each ascending)
```

## Applications

- Ordering records, schedules, and search results.
- Inversion counting measures how far an array is from sorted order.
- Sorting coordinates enables efficient Manhattan pair-distance aggregation.
- Grouping by a key (such as parity) supports later scans and partitioning.

## How It Works

1. Define the requested ordering and any tie-breaking rule.
2. Apply a sorting algorithm or split the data into ordered portions.
3. For inversion counting, merge two sorted halves; when a right-side value is smaller, count all remaining left-side values.
4. For pair distances, sort one coordinate dimension and add each value's distance from all preceding values using a prefix sum.
5. Accumulate in a type wide enough for the maximum possible total.

## Problems / Limitations

- Sorting changes the input unless a copy is made.
- Comparison sorting generally costs O(n log n), even if the final task only needs one small fact.
- Stable ordering and tie-breaking are not guaranteed by every algorithm.
- Inversion counts and pair-distance sums can exceed 32-bit integer range.
- Sorting both coordinate axes independently is valid for summing Manhattan distances because the x and y absolute-difference sums separate; it would not preserve original point pairings for other geometric tasks.

## Time & Space Complexity

| Implemented task | Time | Extra space |
|---|---:|---:|
| Count inversions using merge sort | O(n log n) | O(n) |
| Segregate evens then odds in ascending order using `std::sort` | O(n log n) | O(log n) typical library sort stack; standard-library details apply |
| Manhattan pair sum, nested-loop method | O(n²) | O(1) |
| Manhattan pair sum, sort coordinates and prefix accumulation | O(n log n) | O(1) auxiliary in the described method, excluding sort internals |

The actual Manhattan-distance source includes both a quadratic and an optimized method. Use a 64-bit accumulator for large coordinates/counts.

## When to Use

- Sort when many later operations benefit from ordered data.
- Use merge-sort counting for inversion problems where quadratic pair enumeration is too slow.
- Use coordinate sorting plus prefix sums for sums of pairwise absolute differences.

## When Not to Use

- Avoid fully sorting if only a kth element is needed and a selection algorithm is more suitable.
- Use a linear partition when order within groups is irrelevant.
- Use a hash-based or counting approach when keys are small and repeated comparison sorting is wasteful.

## Types / Variations

- Comparison sorts: merge sort, quicksort, heapsort, insertion sort.
- Non-comparison sorts: counting sort and radix sort under suitable key constraints.
- Stable and unstable sorts; in-place and auxiliary-memory sorts.
- Sorting by a custom key, such as parity followed by numeric value.

## DSA / Interview Notes

- Confirm whether equal elements must retain their original relative order.
- In merge-based inversion counting, use strict `>`; equal values are not inversions.
- Avoid overflow in pair counts and accumulated distances.
- A custom comparator must be a strict weak ordering.

