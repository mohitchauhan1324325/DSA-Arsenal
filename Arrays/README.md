# Arrays

An **array** stores elements in an indexed sequence. It is a foundational structure for representing ordered data and is the basis for many techniques in this repository, including binary search, sorting, and numeric scans.

## Features / Characteristics

| Feature | Description |
|---|---|
| Structure | Elements are addressed by integer indices, usually from `0` |
| Access | Direct indexed access is O(1) |
| Ordering | Preserves positional order; values need not be sorted |
| Memory | Contiguous storage for a conventional array; dynamic arrays may reallocate |
| Type | Linear data structure; fixed arrays are static-size, vectors can grow |
| Mutation | Elements can be changed; inserting/deleting in the middle shifts elements |

## Visual Structure

```text
Index:   0       1       2       3
       +-------+-------+-------+-------+
Value: |   4   |  12   |   7   |  25   |
       +-------+-------+-------+-------+
                   array[2] -> 7
```

## Applications

- Storing sequences, matrices, buffers, and lookup tables.
- Implementing heaps, hash-table buckets, and graph adjacency lists.
- Prefix sums, two pointers, sliding windows, sorting, and dynamic programming.
- This folder currently organizes array-related implementations in [`Binary-Search/`](Binary-Search/), [`Maths/`](Maths/), and [`Sorting/`](Sorting/).

## How It Works

1. Allocate storage for elements (fixed-size or dynamically managed).
2. Read or update an element by its index.
3. Traverse by incrementing an index from the first element to the last.
4. For insertion or deletion in the middle of an ordered sequence, shift subsequent elements.
5. Apply a suitable scan, sorting, or search algorithm to answer the problem.

## Problems / Limitations

- Searching an unsorted array takes linear time.
- Middle insertion/deletion takes linear time due to shifting.
- Fixed-size arrays cannot grow; dynamic arrays may copy all elements on resize.
- Large sparse index ranges waste space, for which maps or sparse structures may be better.
- Index bounds and integer overflow in accumulated values require care.

## Time & Space Complexity

| Operation | Typical complexity |
|---|---:|
| Access/update by index | O(1) |
| Search unsorted values | O(n) |
| Append to dynamic array | Amortized O(1); resize event O(n) |
| Insert/delete at arbitrary position | O(n) |
| Iterate | O(n) |

**Space Complexity:** O(n) for `n` stored elements; a dynamic array may reserve extra capacity.

## When to Use

- Use arrays when indexed access, compact storage, and sequential traversal matter.
- Use a dynamic array when the number of elements changes but random access is still useful.

## When Not to Use

- Prefer a linked structure when frequent insertions/deletions at known positions outweigh random access.
- Prefer a hash map for frequent key-based lookups or a tree when sorted dynamic queries are required.

## Types / Variations

- **Static array:** fixed length after creation.
- **Dynamic array / vector:** resizable array with amortized constant-time append.
- **Multidimensional array:** array of arrays or contiguous matrix storage.
- **Sorted array:** maintains order to enable binary search, at the cost of more expensive updates.

## DSA / Interview Notes

- Check empty and one-element inputs, duplicates, negative values, and boundary indices.
- For sorted arrays, look for binary search or two-pointer solutions.
- For contiguous subarray questions, consider prefix sums or sliding windows.
- State whether a proposed algorithm mutates the input and account for extra storage.

