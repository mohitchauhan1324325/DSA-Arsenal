/*
Kth Smallest Number in Multiplication Table

Hard

Nearly everyone has used the Multiplication Table. The multiplication table of
size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n
multiplication table.


Example 1:
Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.

Example 2:
Input: m = 2, n = 3, k = 6
Output: 6
Explanation: The 6th smallest number is 6.


Constraints:

1 <= m, n <= 3 * 104
1 <= k <= m * n


Time Complexity: (O(m log(mn)))
Space Complexity: (O(1))


Topics:
Principal, Math, Binary Search

*/

class Solution {
public:
  int findKthNumber(int m, int n, int k) {

    long long low = 1;
    long long high = m * n;

    while (low < high) {

      long long mid = low + (high - low) / 2;
      long long count = 0;

      for (int i = 1; i <= m; i++) {
        count += min((long long)n, mid / i);
      }

      if (count >= k) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};