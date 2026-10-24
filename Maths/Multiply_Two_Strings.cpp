/*
Multiply Two Strings

Difficulty: Medium

Given two numbers as strings s1 and s2. Calculate their Product.
Note: The numbers can be negative and You are not allowed to use any built-in
function or convert the strings to integers. There can be zeros in the begining
of the numbers. You don't need to specify '+' sign in the begining of positive
numbers.

Examples:

Input: s1 = "0033", s2 = "2"
Output: "66"
Explanation: 33 * 2 = 66

Input: s1 = "11", s2 = "23"
Output: "253"
Explanation: 11 * 23  = 253

Input: s1 = "123", s2 = "0"
Output: "0"
Explanation: Anything multiplied by 0 is equal to 0.

Constraints:
1 ≤ s1.size(), s2.size() ≤ 103
s1 consists of digits and the character -
s2 consists of digits and the character -

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string multiplyStrings(string &s1, string &s2) {
    // code here

    bool neg1 = false;
    bool neg2 = false;

    if (s1[0] == '-') {
      s1.erase(0, 1);
      neg1 = true;
    }
    if (s2[0] == '-') {
      s2.erase(0, 1);
      neg2 = true;
    }
    int idx = 0;

    while (s1.size() > 1 && s1[0] == '0') {
      s1.erase(0, 1);
    }

    while (s2.size() > 1 && s2[0] == '0') {
      s2.erase(0, 1);
    }
    int n = s1.size();
    int m = s2.size();
    int sum = 0;

    vector<int> ans(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        int a = s1[i] - '0';
        int b = s2[j] - '0';
        int mul = a * b;
        sum = mul + ans[i + j + 1];
        ans[i + j + 1] = sum % 10;
        ans[i + j] += sum / 10;
      }
    }

    int i = 0;

    while (i < ans.size() - 1 && ans[i] == 0)
      i++;

    string result = "";

    for (; i < ans.size(); i++) {
      result += (ans[i] + '0');
    }

    if (result == "0")
      return "0";

    if (neg1 != neg2)
      result = "-" + result;

    return result;
  }
};

int main() {
  Solution sol;

  string s1 = "234";
  string s2 = "44";

  cout << sol.multiplyStrings(s1, s2);

  return 0;
}