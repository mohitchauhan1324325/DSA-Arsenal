# Graphs

A **graph** is a set of vertices connected by edges. It models relationships and networks, allowing problems such as reachability, connectivity, ordering, and shortest paths to be expressed systematically.

## Features / Characteristics

| Feature | Description |
|---|---|
| Shape | Linear or non-linear; may contain cycles and disconnected components |
| Edges | Directed/undirected and weighted/unweighted |
| Representations | Adjacency list O(V+E); adjacency matrix O(V²) |
| Traversals | BFS uses a queue; DFS uses recursion or a stack |
| Complexity | Many traversals take O(V+E) with adjacency lists |

## Visual Structure

```text
      A ----- B
      |       |
      C ----- D ----- E

Adjacency list:
A: B, C     B: A, D     C: A, D
D: B, C, E  E: D
```

## Applications

- Road, transit, and communication networks.
- Social relationships and recommendation links.
- Build dependencies, course prerequisites, and task scheduling.
- Network routing, web link analysis, and connected-component detection.

## How It Works

1. Represent each vertex and its neighbors.
2. Choose a traversal or graph algorithm that matches edge direction and weights.
3. Mark vertices when discovered to avoid revisiting cycles.
4. Use BFS for unweighted shortest paths or level order; use DFS for exploration and components.
5. For weighted paths, topological ordering, or connectivity, use an algorithm with the required assumptions.

## Problems / Limitations

- Adjacency matrices use O(V²) memory even for sparse graphs.
- Cycles and disconnected components require careful visited-state handling.
- Algorithm assumptions matter: Dijkstra's algorithm does not support negative edge weights.
- Large recursive DFS can overflow the call stack.
- Modeling vertices/edges incorrectly can omit important relationships.

## Time & Space Complexity

| Operation / representation | Complexity |
|---|---:|
| Store adjacency list | O(V + E) space |
| Store adjacency matrix | O(V²) space |
| BFS/DFS with adjacency list | O(V + E) time, O(V) traversal state |
| BFS/DFS with matrix | O(V²) time |
| Dijkstra with binary heap and adjacency list | O((V + E) log V) typical |

`V` is the number of vertices and `E` the number of edges; exact algorithm bounds depend on representation and graph assumptions.

## When to Use

- Use a graph when entities have arbitrary pairwise relationships.
- Use BFS for unweighted shortest paths and DFS for reachability or component exploration.
- Use a sparse adjacency list for most sparse real-world networks.

## When Not to Use

- A simple sequence or hierarchy may be better represented as an array or tree.
- Avoid an adjacency matrix for a very large sparse graph unless constant-time edge tests justify the memory.
- Do not use a shortest-path algorithm without checking its weight assumptions.

## Types / Variations

- Directed and undirected.
- Weighted and unweighted.
- Cyclic and acyclic; DAGs.
- Sparse and dense.
- Connected, disconnected, and bipartite graphs.

## DSA / Interview Notes

- Clarify whether edges are directed, weighted, and whether input can be disconnected.
- Mark nodes on enqueue/discovery in BFS to prevent duplicates.
- For unweighted shortest path, store parent/distance while traversing.
- Test isolated vertices, self-loops, parallel edges, and cycles.
