/*
Nth Magical Number

Hard

A positive integer is magical if it is divisible by either a or b.

Given the three integers n, a, and b, return the nth magical number. Since the
answer may be very large, return it modulo 109 + 7.


Example 1:
Input: n = 1, a = 2, b = 3
Output: 2

Example 2:
Input: n = 4, a = 2, b = 3
Output: 6


Constraints:

1 <= n <= 109
2 <= a, b <= 4 * 104


Time Complexity: (O(n log(n min(a,b))))
Space Complexity: (O(1))


Topics
Principal, Math, Binary Search, Least Common Multiple, Inclusion-Exclusion Principle

*/

class Solution {
public:
  long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }

  int nthMagicalNumber(int n, int a, int b) {

    long long ab = lcm(a, b);

    long long low = 1;
    long long high = 1LL * min(a, b) * n;

    while (low < high) {
      long long mid = low + (high - low) / 2;

      long long count = mid / a + mid / b - mid / ab;

      if (count >= n) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return low % 1000000007;
  }
};