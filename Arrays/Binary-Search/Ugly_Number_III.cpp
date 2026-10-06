/*
Ugly Number III

Medium

An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.

Example 1:
Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.

Example 2:
Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.

Example 3:
Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.


Constraints:
1 <= n, a, b, c <= 109
1 <= a * b * c <= 1018
It is guaranteed that the result will be in range [1, 2 * 109].

Time: O(log(n × min(a,b,c)))
Space: O(1)
*/

class Solution {
public:
  long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }

  int nthUglyNumber(int n, int a, int b, int c) {

    long long ab = lcm(a, b);
    long long ac = lcm(a, c);
    long long bc = lcm(b, c);
    long long abc = lcm(ab, c);

    long long start = 1;
    long long end = 1LL * min({a, b, c}) * n;

    while (start < end) {

      long long mid = start + (end - start) / 2;

      long long count = mid / a + mid / b + mid / c - mid / ab - mid / ac -
                        mid / bc + mid / abc;

      if (count >= n) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }

    return start;
  }
};