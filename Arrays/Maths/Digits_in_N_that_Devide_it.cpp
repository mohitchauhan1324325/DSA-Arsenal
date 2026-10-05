/*
Digits in N that Divide it

Difficulty: Medium

Given a non-negative integer s represented as a string, count the number of
digits in s that divide the number represented by s.

A digit is considered valid only if it is non-zero and the number represented by
s is divisible by that digit.

If a digit appears multiple times in s, each occurrence should be counted
separately.

Examples:

Input: s = "35"
Output: 1
Explanation: The digit 5 divides 35, but the digit 3 does not. So the answer
is 1.

Input: s = "1122324"
Output: 7
Explanation: Every digit in "1122324" divides 1122324. So the answer is 7.

Constraints:
1 ≤ s.size() ≤ 106
s consists only of digits

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int divisibleByDigits(string &s) {
    int count = 0;

    vector<bool> v(10, {false});

    for (int i = 1; i <= 9; i++) {

      int rem = 0;
      for (char c : s) {
        rem = (rem * 10 + (c - '0')) % i;
      }

      v[i] = (rem == 0);
    }

    for (char ch : s) {
      int d = ch - '0';

      if (d != 0 && v[d]) {
        count++;
      }
    }

    return count;
  }
};

int main() {

  Solution sol;
  string s = "1122324";

  int res = sol.divisibleByDigits(s);

  cout << res;

  return 0;
}