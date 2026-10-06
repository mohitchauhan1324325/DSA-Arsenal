# Trees

A tree is a connected, acyclic structure of nodes arranged in parent-child relationships. Trees represent hierarchies and support efficient search when they maintain suitable ordering or balance.

## Features / Characteristics

| Feature | Description |
|---|---|
| Structure | Rooted hierarchy; each non-root node has one parent |
| Shape | No cycles; a tree with n nodes has n−1 edges |
| Traversals | DFS orders and breadth-first/level-order |
| Search cost | O(height) in an ordered search tree |
| Balance | Balanced height O(log n); skewed height O(n) |
| Type | Non-linear; usually mutable |

## Visual Structure

```text
             8
           /   \
          3     12
         / \      \
        1   6      15

Inorder traversal: 1, 3, 6, 8, 12, 15
```

## Applications

- File systems and organizational hierarchies.
- Syntax trees and compiler expression evaluation.
- Search indexes, ordered maps, and priority structures.
- Decision trees, XML/JSON structures, and hierarchical UI models.

## How It Works

1. Begin at the root and follow child links.
2. Traverse with DFS (preorder, inorder, postorder) or BFS (level order).
3. For a binary search tree, compare the target with each node and choose left or right.
4. Insert/delete while preserving any ordering and balance invariants.
5. Use rotations or rebuilding for self-balancing variants.

## Problems / Limitations

- A plain BST can become skewed, making operations O(n).
- Recursive traversal on a deep tree may overflow the call stack.
- Pointer-based nodes incur allocation and cache-locality costs.
- Balancing improves bounds but increases implementation complexity.
- A tree is not appropriate for arbitrary cyclic relationships.

## Time & Space Complexity

| Operation | Balanced BST | Unbalanced BST worst case |
|---|---:|---:|
| Search | O(log n) | O(n) |
| Insert/delete | O(log n) | O(n) |
| Full traversal | O(n) | O(n) |
| DFS recursion stack | O(log n) balanced | O(n) worst case |
| Store n nodes | O(n) | O(n) |

## When to Use

- Use trees for hierarchical information or ordered dynamic data.
- Use a balanced search tree for ordered lookup, predecessor/successor, or range iteration.
- Use a heap when only repeated min/max retrieval is needed.

## When Not to Use

- Use arrays for compact indexed data and hash maps for unordered key lookup.
- Use a graph when relationships can be cyclic or nodes can have multiple independent parents.
- Avoid a plain unbalanced BST when adversarial order is possible.

## Types / Variations

- General tree and binary tree.
- Binary search tree (BST).
- AVL and red-black balanced trees.
- Heap, B-tree/B+ tree, and segment tree.
- Trie (prefix tree), documented separately.

## DSA / Interview Notes

- State whether the tree is a BST; binary-tree shape alone does not imply ordering.
- Test empty tree, one node, skewed tree, and duplicate-key policy.
- Know recursive and iterative traversals.
- Use a queue for level order and track parent/depth where reconstruction is needed.



