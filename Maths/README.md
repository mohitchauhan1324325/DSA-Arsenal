# Maths for DSA

Mathematical DSA problems use number properties and arithmetic procedures—such as divisibility, prime factors, digit manipulation, and gcd—to compute answers without necessarily storing a larger data structure. The files here cover those areas, including multiplication of numeric strings.

## Features / Characteristics

| Feature | Description |
|---|---|
| Input | Integers, digit sequences, or numeric strings |
| Core ideas | Divisibility, remainders, factors, primes, and arithmetic identities |
| Memory | Often constant for scalar operations; sieves and digit buffers use additional storage |
| Correctness risks | Zero/negative inputs, overflow, and conversion assumptions |
| Runtime | Depends on input magnitude and algorithm (digits, square root, or full range) |

## Visual Structure

```text
Number n
  ├── divide / remainder ──> inspect factors or digits
  ├── gcd(a, b) ───────────> gcd(b, a mod b)
  └── many primality tests -> sieve once -> answer queries
```

## Applications

- Number theory tasks such as GCD/LCM, prime checks, divisors, and prime factorization.
- Parsing, reversing, and validating numeric text.
- Arithmetic on values too large for built-in integer types, such as multiplying numeric strings.
- Precomputing prime or factor information for repeated queries.

## How It Works

1. Identify the numeric property required (digits, factors, primality, or arithmetic).
2. Choose an algorithm based on scale: inspect digits, iterate to `sqrt(n)`, use Euclid's algorithm, or sieve a range.
3. Preserve signs and handle zero/one as special cases where relevant.
4. Use a sufficiently wide type or digit-string representation for intermediate results.
5. Return the computed result in the required numeric or textual format.

## Problems / Limitations

- Narrow integer types can overflow before the final answer is returned.
- Trial division through `n` is too slow for large `n`; checking factors only through `sqrt(n)` is usually better.
- A sieve requires O(n) memory, so it is unsuitable for an enormous range.
- Digit algorithms can fail on zero, negative numbers, or leading zeroes if these cases are not defined.
- Multiplying numeric strings avoids fixed-width conversion but still requires handling carry and output size.

## Time & Space Complexity

| Technique represented in this folder | Time | Extra space |
|---|---:|---:|
| Arithmetic on fixed-width values | O(1) | O(1) |
| Inspect/reverse/sum digits | O(d) | O(1), excluding string output |
| Euclidean GCD | O(log min(a, b)) | O(1) iterative |
| Trial prime/factor/divisor checks | O(sqrt(n)) | O(1), excluding output |
| Sieve of Eratosthenes through n | O(n log log n) | O(n) |
| Grade-school multiplication of strings of lengths n and m | O(nm) | O(n + m) |

`d` is the number of digits. Individual files may use different implementations; these are the relevant standard bounds.

## When to Use

- Use number properties to replace brute-force search when constraints support it.
- Use Euclid for GCD/LCM-related problems and a sieve for many queries over a bounded range.
- Use strings when numbers can exceed built-in integer limits.

## When Not to Use

- Avoid trial division for very large values or a large batch of primality queries.
- Avoid converting large numeric strings to a built-in type if overflow is possible.
- Use modular arithmetic only when the problem's constraints and required result allow it; it is not interchangeable with exact arithmetic.

## Types / Variations

- Digit processing and digital-root style problems.
- GCD, LCM, and divisibility.
- Prime testing, sieve, and prime factorization.
- Exact arithmetic on strings and pairwise factor counting.

## DSA / Interview Notes

- Define the input domain first, especially whether zero and negatives are allowed.
- In factor loops, use a safe condition such as `i <= n / i` to avoid overflow from `i * i`.
- Use a wide accumulator for sums/products even when each input fits in `int`.
- For repeated queries, compare preprocessing cost with the number of queries.

