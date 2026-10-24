/*
Reversing the equation

Difficulty: Easy

Given a mathematical equation that contains only numbers and +, -, *, /. Print
the equation in reverse, such that the equation is reversed, but the numbers
remain the same. It is guaranteed that the given equation is valid, and there
are no leading zeros.

Example 1:

Input:
S = "20-3+5*2"
Output: 2*5+3-20
Explanation: The equation is reversed with
numbers remaining the same.

Example 2:

Input:
S = "5+2*56-2/4"
Output: 4/2-56*2+5
Explanation: The equation is reversed with
numbers remaining the same.

Your Task:
You don't need to read input or print anything. Your task is to complete the
function reverseEqn() which takes the string S representing the equation as
input and returns the resultant string representing the equation in reverse.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).

Constraints:
1<=|S|<=105
The string contains only the characters '0' - '9', '+', '-', '*', and '/'.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string reverseEqn(string s) {
    // code here.

    string ans = "";
    string operand = "";

    for (int i = s.length() - 1; i >= 0; i--) {

      if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {

        ans += operand;
        ans += s[i];
        operand = "";
      } else {
        operand = s[i] + operand;
      }
    }

    ans += operand;

    return ans;
  }
};

int main() {

  Solution sol;

  string s = "20-3+5*2";
  string ans = sol.reverseEqn(s);

  cout << ans;

  return 0;
}