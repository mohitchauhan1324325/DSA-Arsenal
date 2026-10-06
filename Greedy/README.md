# Greedy Algorithms

A greedy algorithm repeatedly makes a locally best eligible choice. It can produce an efficient global solution when the problem has a property that proves each choice is safe.

## Features / Characteristics

| Feature | Description |
|---|---|
| Decision pattern | Commit to a local choice and continue |
| State | Usually small; prior choices are not reconsidered |
| Runtime | Often dominated by sorting or a priority queue |
| Correctness | Requires an exchange, cut, or other proof |
| Space | Often O(1) auxiliary after sorting, but varies |

## Visual Structure

```text
Candidates -> rank by a justified rule -> choose eligible best
                    ^                         |
                    |                         v
               update state <- repeat until complete
```

## Applications

- Activity/interval scheduling.
- Minimum spanning trees and Huffman coding.
- Resource allocation and deadline scheduling with suitable assumptions.
- Optimal prefix codes and locally optimal routing decisions.

## How It Works

1. Define the objective and a candidate choice rule.
2. Select the best currently feasible option.
3. Update the remaining candidates/state.
4. Repeat until the solution is complete.
5. Prove that an optimal solution exists containing the selected choice; testing alone is not a proof.

## Problems / Limitations

- A plausible local choice can block a better global solution.
- Greedy does not generally work for arbitrary knapsack, change-making, or scheduling variants.
- A wrong tie-breaking rule can invalidate an otherwise sound strategy.
- Greedy algorithms may need sorting, so they are not always linear.

## Time & Space Complexity

| Pattern | Typical time | Typical extra space |
|---|---:|---:|
| Sort then scan | O(n log n) | O(1) to O(n), algorithm-dependent |
| Repeated best choice with binary heap | O((n + k) log n), task-dependent | O(n) |
| Simple ordered scan | O(n) | O(1) |

There is no generic greedy bound; analyze the data structure and number of decisions in each problem.

## When to Use

- Use greedy when the local choice can be proven safe and leads to an optimal substructure.
- Use it for large inputs where the proof allows a simpler, faster one-pass or sort-and-scan solution.

## When Not to Use

- Do not use a greedy rule based only on intuition or a few examples.
- Prefer DP or exhaustive search when a choice must be revised or future trade-offs matter.
- Avoid greedy when the problem's constraints do not satisfy the required proof property.

## Types / Variations

- Sort-and-select.
- Interval scheduling.
- Greedy with a priority queue.
- Minimum spanning tree algorithms (Kruskal and Prim).
- Huffman coding and exchange-argument strategies.

## DSA / Interview Notes

- State the greedy-choice property and justify why a choice is safe.
- Search for a small counterexample before committing to a rule.
- Clarify tie handling and whether intervals include endpoints.
- Compare against DP for variants with capacity/state interactions.

