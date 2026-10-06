# Backtracking

Backtracking explores possible solutions one choice at a time. It solves combinatorial and constraint problems by building a partial answer, rejecting invalid branches early, and undoing choices to try alternatives.

## Features / Characteristics

| Feature | Description |
|---|---|
| Structure | Search tree of decisions |
| Processing | Depth-first exploration, often recursive |
| State | Partial candidate plus choices still available |
| Pruning | Stops exploring a branch that cannot yield a valid answer |
| Complexity | Commonly exponential or factorial in the worst case |
| Memory | O(depth) call/state stack, excluding stored answers |

## Visual Structure

```text
                 []
               /    \
             [A]     [B]
            /   \      \
         [A,C] [A,D]   [B,C]
           |     x       |
        answer prune   answer
```

## Applications

- Permutations, combinations, subsets, and word-search paths.
- Constraint problems such as Sudoku and N-Queens.
- Maze traversal and generating valid configurations.

## How It Works

1. Check whether the current partial state is complete; if so, record or return it.
2. Enumerate choices allowed at this state.
3. Apply one choice and update the state.
4. Recurse only if the updated state remains feasible.
5. Undo the choice exactly before examining the next branch.

## Problems / Limitations

- The number of candidates can grow exponentially.
- Weak pruning may make a correct algorithm too slow.
- Deep recursion can overflow the call stack.
- Shared mutable state is error-prone if it is not restored after each branch.
- Dynamic programming or a direct mathematical construction may be better when subproblems repeat heavily.

## Time & Space Complexity

| Operation / cost | Complexity |
|---|---:|
| Worst-case search | O(b^d), where `b` is branching factor and `d` is depth |
| Permutation enumeration | O(n · n!) including output construction |
| Recursion/state stack | O(d) |
| Store all results | Depends on number and size of results; may dominate memory |

There is no single complexity for all backtracking problems; pruning and constraints determine practical work.

## When to Use

- Use it when the answer is built from a sequence of constrained choices.
- Use it when all valid solutions must be generated or the search space is small after pruning.
- Use it when a partial choice can be rejected before completing the candidate.

## When Not to Use

- Avoid unpruned brute-force search for large input sizes.
- Prefer DP when the same subproblems recur, or a greedy/graph algorithm when it has a correctness proof and better bounds.

## Types / Variations

- Subset and combination generation.
- Permutation generation.
- Constraint satisfaction and path search.
- Branch-and-bound, which prunes using bounds on the best possible result.

## DSA / Interview Notes

- Identify the state, choices, goal condition, and pruning condition before coding.
- Handle duplicates deliberately to avoid repeated answers.
- Test empty input, no-solution input, and the smallest valid candidate.
- Explain whether the function returns one answer or collects all answers.
