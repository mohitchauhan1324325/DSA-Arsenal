# Binary Search in Arrays

Binary search reduces a search range by half using sorted order or a monotonic yes/no condition. The implementations in this folder include boundary searches, rotated-array and matrix searches, order-statistic problems, and binary search on an answer.

## Features / Characteristics

| Feature | Description |
|---|---|
| Input property | Sorted order or a proven monotonic predicate is required |
| Access pattern | Repeatedly inspect a midpoint |
| Search space | Can be array indices or a numeric answer range |
| Typical time | O(log n) for ordinary sorted-array search |
| Duplicates | Need explicit lower/upper-bound logic |
| Special cases | Some variants (e.g. duplicates in rotated data) can degrade to O(n) |

## Visual Structure

```text
Sorted values: [ 2 | 5 | 8 | 12 | 16 | 23 | 38 ]
                 L             M              R
Target 16 > 12: discard the left half
                              [ 16 | 23 | 38 ]
                                 L    M    R
```

## Applications

- Finding a value, insertion position, first/last occurrence, or peak.
- Searching rotated arrays and row/column-sorted matrices.
- Selecting a kth value or minimizing/maximizing a feasible quantity.
- This folder includes examples such as Aggressive Cows, kth pair distance, kth matrix element, and single element in a sorted array.

## How It Works

1. Establish an interval that contains the answer.
2. Compute a safe midpoint, such as `left + (right - left) / 2`.
3. Compare the midpoint with the target or evaluate the feasibility predicate.
4. Discard the half that cannot contain the answer.
5. Stop when the target or required boundary is isolated; update loop bounds carefully.

For binary search on an answer, sort/preprocess if needed, test whether a candidate answer is feasible, and narrow the numeric range based on that result.

## Problems / Limitations

- It is invalid when neither the data nor the tested condition has the needed ordering/monotonicity.
- Off-by-one errors and incorrect equality handling commonly break boundary searches.
- Duplicate values can make rotated-array logic ambiguous and force linear worst-case work.
- Binary search over an answer is only correct after proving feasibility is monotonic.
- Linked lists do not offer cheap midpoint access, so ordinary binary search is not efficient there.

## Time & Space Complexity

| Technique / example | Time | Extra space |
|---|---:|---:|
| Standard sorted-array search / lower or upper bound | O(log n) | O(1) iterative |
| Search in rotated array with duplicates | O(log n) average; O(n) worst | O(1) |
| Staircase search in an `r × c` sorted matrix | O(r + c) | O(1) |
| Aggressive Cows: sort, then binary-search distance with greedy checks | O(n log n + n log R) | O(1) auxiliary beyond sorting, implementation-dependent |
| Kth pair distance: sort, then count pairs per candidate distance | O(n log n + n log W) | O(1) auxiliary beyond sorting |

`R`/`W` denotes the size of the searched answer range; exact bounds and costs vary among files.

## When to Use

- Use it when the candidate values are sorted or the answer predicate changes monotonically.
- Use it to find a boundary rather than checking every candidate individually.
- Use it for numeric optimization when a fast feasibility test exists.

## When Not to Use

- Use a linear scan for unsorted data without a monotonic property or for very small inputs.
- Use a hash set/map for repeated membership queries on unsorted values.
- Do not apply binary search to a linked list or an unproven feasibility rule.

## Types / Variations

- Exact-value search; lower bound and upper bound.
- Search in rotated sorted arrays; peak/boundary search.
- Binary search on a monotonic answer predicate.
- Matrix search, which may use binary search per row or a staircase walk depending on matrix ordering.

## DSA / Interview Notes

- Decide whether the interval is inclusive or half-open and use that convention throughout.
- Write down what `left`, `right`, and the loop invariant mean.
- Test absent targets, endpoints, all-equal values, and two-element ranges.
- For answer search, state the smallest/largest possible answer and prove the check function's monotonic direction.
- This folder's duplicate rotated-array and sorted-matrix solutions do not all have O(log n) complexity; use each input's exact ordering guarantees.

