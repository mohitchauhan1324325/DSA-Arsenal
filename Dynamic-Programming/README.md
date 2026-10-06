# Dynamic Programming

Dynamic programming (DP) solves problems by dividing them into smaller states, computing each state once, and reusing its result. It is important when subproblems overlap and a larger answer can be built from smaller answers.

## Features / Characteristics

| Feature | Description |
|---|---|
| Required structure | Overlapping subproblems and a valid recurrence |
| State | Captures enough information to define one subproblem |
| Evaluation | Top-down memoization or bottom-up tabulation |
| Time | Usually number of states × transitions per state |
| Space | Stored states; sometimes reducible to recent layers |
| Type | Algorithmic technique, not a standalone data structure |

## Visual Structure

```text
                 dp[4]
                /     \
             dp[3]    dp[2]
             /  \       |
          dp[2] dp[1]  dp[1]

Memoization stores dp[1] and dp[2] after first computation.
```

## Applications

- Knapsack and coin-change optimization/counting.
- Longest increasing subsequence and edit distance.
- Grid path counting, sequence alignment, and interval problems.
- Planning problems with a finite, reusable state space.

## How It Works

1. Define the state (for example, `dp[i][capacity]`).
2. Identify base cases.
3. Derive a recurrence from smaller states.
4. Evaluate in dependency order or recurse with memoization.
5. Return the target state; reconstruct choices if the problem asks for an actual solution.

## Problems / Limitations

- State design and recurrence errors are difficult to diagnose.
- Too many dimensions can cause excessive time and memory.
- Some recurrences are not well-founded or need careful iteration ordering.
- DP may not help when subproblems do not overlap.
- A greedy strategy may be faster when its choice rule can be proven correct.

## Time & Space Complexity

| Cost | Typical bound |
|---|---:|
| Time | O(S × T), where `S` is number of states and `T` is transitions per state |
| Space | O(S) for stored states; may be reduced when only prior layers are needed |
| Recursion stack (top-down) | Up to the maximum dependency depth |

There is no universal DP complexity; derive it from the state count and transitions for the particular problem.

## When to Use

- Use DP when the problem has optimal substructure and overlapping subproblems.
- Use it when all choices can be represented with a manageable state space.
- Use it when an exhaustive search repeats the same subproblems.

## When Not to Use

- Avoid DP if the state space is too large for constraints.
- Do not use it just because recursion is present; first establish reuse and a valid recurrence.
- Consider greedy, graph algorithms, or direct formulas when they are correct and simpler.

## Types / Variations

- Memoization and tabulation.
- 1D, 2D, and multidimensional DP.
- Knapsack, sequence, interval, tree, and bitmask DP.
- Space-optimized DP and digit DP.

## DSA / Interview Notes

- Write the state meaning in one sentence.
- Check base cases and transition order with a tiny example.
- Estimate states × transitions before implementation.
- Distinguish counting, feasibility, and optimization recurrences.

