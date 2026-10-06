# Hashing

Hashing maps a key to a bucket using a hash function. Hash tables use this mapping to support fast key lookup, insertion, and deletion on average, making hashing a core tool for membership and frequency problems.

## Features / Characteristics

| Feature | Description |
|---|---|
| Structure | Buckets addressed by a computed hash |
| Access | Key-based rather than index-based |
| Average operations | O(1) lookup/insert/delete |
| Worst case | O(n) with severe collisions |
| Ordering | No sorted-order guarantee |
| Space | O(n) entries plus bucket/table overhead |

## Visual Structure

```text
hash("pear") -> bucket 2

0: [ ... ]
1: [ ... ]
2: ["pear" -> value] -> ["plum" -> value]  collision chain
3: [ ... ]
```

## Applications

- Counting frequencies and detecting duplicates.
- Caches, dictionaries, symbol tables, and in-memory indexes.
- Deduplicating events and grouping data by a key.
- Fast membership testing in applications and algorithms.

## How It Works

1. Compute a hash value from the key.
2. Map the hash to a bucket in the table.
3. Compare keys in that bucket to find an exact match.
4. Insert, update, or remove the associated entry.
5. Resize and redistribute entries when the load factor becomes too high.

## Problems / Limitations

- Collisions can degrade operations to linear time.
- Hash maps do not naturally support sorted range queries.
- Resizing causes occasional O(n) rehashing.
- Keys used in a map must preserve consistent hash/equality behavior while stored.
- Hashing untrusted inputs may need collision-attack protections.

## Time & Space Complexity

| Operation | Average | Worst case |
|---|---:|---:|
| Search by key | O(1) | O(n) |
| Insert/update | O(1) amortized | O(n) |
| Delete | O(1) average | O(n) |
| Store n entries | O(n) | O(n) |

## When to Use

- Use a hash set/map for frequent exact membership, counting, or key-value access.
- Use it when ordering is unnecessary and expected constant-time access is valuable.

## When Not to Use

- Use a balanced search tree for ordered traversal or range queries.
- Use an array for dense integer keys with a small known range.
- Use a trie for prefix searches over strings.

## Types / Variations

- Hash map/dictionary and hash set.
- Separate chaining and open addressing.
- Static/perfect hashing for fixed key sets.
- Rolling hashes for string matching (with collision verification where correctness requires it).

## DSA / Interview Notes

- Consider a hash map for two-sum, frequency counts, and duplicate checks.
- Use `find`/membership checks rather than accidentally inserting during lookup.
- Account for duplicate keys, empty input, and collision-safe equality checks.
- Do not claim worst-case O(1); describe average/amortized assumptions.
