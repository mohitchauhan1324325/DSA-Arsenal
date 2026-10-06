# Trie (Prefix Tree)

A trie stores keys as paths of characters or tokens. Shared prefixes share the same path, making prefix lookup and dictionary-style search efficient in proportion to the key length.

## Features / Characteristics

| Feature | Description |
|---|---|
| Structure | Rooted tree with labeled child edges |
| Search | O(L) for a key of length L, given constant-time child lookup |
| Prefix queries | Natural; locate prefix node, then inspect descendants |
| Space | Up to O(total key characters), with node/child-container overhead |
| Ordering | Depends on child representation and traversal order |

## Visual Structure

```text
root
 └─ c
    └─ a
       ├─ t*       cat
       └─ r
          └─ d*    card

* marks the end of a complete stored key.
```

## Applications

- Autocomplete and prefix search.
- Spell-checking and dictionary lookup.
- IP routing/longest-prefix matching (with suitable bit tries).
- Word games and search over shared prefixes.

## How It Works

1. Start at the root.
2. For each key character, follow its child edge or create a new node when inserting.
3. Mark the final node as the end of a stored word.
4. Search by following the same character path and checking the end marker.
5. For prefix completion, enumerate the subtree below the prefix node.

## Problems / Limitations

- A node-per-character design can use far more memory than storing strings in a hash set.
- Child maps, pointers, and allocations add overhead and reduce cache locality.
- Deletion must preserve nodes that are prefixes of other keys.
- Case, normalization, and alphabet choice affect child identity and memory use.
- Listing all completions costs at least the size of the returned output.

## Time & Space Complexity

| Operation | Complexity |
|---|---:|
| Insert key length L | O(L) expected with hash-map children; alphabet-dependent with arrays |
| Search key length L | O(L) |
| Prefix lookup length P | O(P) |
| Enumerate completions | O(P + visited subtree/output size) |
| Space | O(total inserted characters) worst case, plus node overhead |

## When to Use

- Use a trie for many prefix queries over a shared vocabulary.
- Use it when predictable lookup by key length is more important than compact storage.

## When Not to Use

- Use a hash set/map for exact lookup when prefix queries are unnecessary.
- Use a sorted array/vector for a small static dictionary or compact storage.
- Avoid a naive trie for huge sparse alphabets without compressed edges or compact child maps.

## Types / Variations

- Array-child trie and map-child trie.
- Compressed/radix trie.
- Bitwise trie for integer keys or IP prefixes.
- Ternary search trie.

## DSA / Interview Notes

- A node can mark both a complete word and a prefix of a longer word.
- Test empty keys, shared prefixes, duplicate insertion, and deletion of a prefix word.
- Distinguish lookup cost from completion-output cost.



