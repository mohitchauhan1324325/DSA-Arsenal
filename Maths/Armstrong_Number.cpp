/*
Armstrong Numbers

Difficulty: Easy

You are given a 3-digit number n, Find whether it is an Armstrong number or not.

An Armstrong number of three digits is a number such that the sum of the cubes
of its digits is equal to the number itself. 371 is an Armstrong number since 33
+ 73 + 13 = 371.

Examples:

Input: n = 153
Output: true
Explanation: 153 is an Armstrong number since 13 + 53 + 33 = 153.

Input: n = 372
Output: false
Explanation: 372 is not an Armstrong number since 33 + 73 + 23 = 378.

Input: n = 100
Output: false
Explanation: 100 is not an Armstrong number since 13 + 03 + 03 = 1.

Constraints:
100 ≤ n < 1000

Expected Complexities
Time Complexity: O(1)
Auxiliary Space: O(1)
*/

#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
  bool armstrongNumber(int n) {
    // code here
    int num = n;
    int res = 0;

    while (num != 0) {
      int temp = num % 10;
      res += pow(temp, 3);
      num /= 10;
    }

    if (res == n) {
      return true;
    }

    return false;
  }
};

int main() { 

    Solution sol;

    int n = 372;

    cout << (sol.armstrongNumber(n) ? "true" : "false");

    return 0; 
}