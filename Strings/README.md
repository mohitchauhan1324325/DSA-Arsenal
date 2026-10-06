# Strings

A string is a sequence of characters or code units used to represent text. String algorithms solve tasks such as searching, comparing, parsing, and transforming text.

## Features / Characteristics

| Feature | Description |
|---|---|
| Structure | Ordered sequence of characters/code units |
| Access | Indexing is usually O(1) by code unit in common runtimes |
| Mutation | Often immutable; builders/buffers support efficient construction |
| Search | Naive matching O(nm); specialized matching can be linear |
| Encoding | Unicode characters may span multiple code units |

## Visual Structure

```text
Text:    c  a  b  a  c  a  b
Index:   0  1  2  3  4  5  6
Pattern:       a  b  a
                 └─ compare window, then shift
```

## Applications

- Search, autocomplete, validation, and parsing.
- Compilers, editors, search engines, and log processing.
- DNA/protein sequence analysis and text-based protocols.
- Serialization and user-facing messages.

## How It Works

1. Define the unit of comparison: byte, code unit, Unicode code point, or grapheme cluster.
2. Scan or preprocess the text/pattern according to the task.
3. Compare characters or use a prefix/hash table to avoid repeated work.
4. Build output with a mutable buffer when many concatenations are needed.
5. Apply normalization/case-folding if the problem defines text equivalence that way.

## Problems / Limitations

- Unicode makes “one character” ambiguous across bytes, code points, and grapheme clusters.
- Repeated concatenation of immutable strings can take O(n²) total time.
- Naive substring search can be O(nm).
- Case-insensitive and normalized equality may differ from byte-for-byte equality.
- Rolling hashes can collide and may need direct verification.

## Time & Space Complexity

| Operation | Typical complexity |
|---|---:|
| Read character by index | O(1) per code unit |
| Scan a string of length n | O(n) |
| Naive pattern search (length m) | O(nm) worst case |
| KMP pattern search | O(n + m) |
| Construct result of length n with a builder | O(n) |
| Repeated immutable concatenation | Can be O(n²) total |

Exact behavior depends on the language's string representation and Unicode operations.

## When to Use

- Use string algorithms when order and content of text are central.
- Use KMP/Z or a suffix structure for repeated/large pattern-search workloads.
- Use a frequency table or hash map for anagram and character-count problems.

## When Not to Use

- Use byte arrays for binary data rather than text-aware operations.
- Use a trie for many prefix queries over a dictionary.
- Avoid repeated immutable concatenation in a loop; use a builder.

## Types / Variations

- Immutable strings and mutable string builders.
- ASCII/byte strings, Unicode code-point strings, and grapheme-aware text.
- Substring, prefix/suffix, palindrome, and pattern-matching algorithms.

## DSA / Interview Notes

- Clarify whether matching is case-sensitive and whether spaces/punctuation matter.
- Test empty strings, repeated characters, overlapping matches, and Unicode constraints.
- For anagram checks, compare frequency counts; for substring search, explain preprocessing.



