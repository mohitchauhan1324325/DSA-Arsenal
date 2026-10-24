/*
Smallest Even Multiple

Easy

Given a positive integer n, return the smallest positive integer that is a
multiple of both 2 and n.

Example 1:

Input: n = 5
Output: 10
Explanation: The smallest multiple of both 5 and 2 is 10.

Example 2:

Input: n = 6
Output: 6
Explanation: The smallest multiple of both 6 and 2 is 6. Note that a number is a
multiple of itself.

Constraints:
1 <= n <= 150
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int smallestEvenMultiple(int n) {

    int res = 0;

    if (n % 2 == 0) {
      res = n;
    } else {
      res = n * 2;
    }

    return res;
  }
};

int main() {

  Solution sol;

  cout << sol.smallestEvenMultiple(5);

  return 0;
}