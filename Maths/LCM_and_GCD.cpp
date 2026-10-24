/*
LCM And GCD

Difficulty: Easy

Given two integers a and b, You have to compute their LCM and GCD and return an
array containing their LCM and GCD.

Examples:

Input: a = 5 , b = 10
Output: [10, 5]
Explanation: LCM of 5 and 10 is 10, while their GCD is 5.

Input: a = 14 , b = 8
Output: [56, 2]
Explanation: LCM of 14 and 8 is 56, while their GCD is 2.

Input: a = 1 , b = 1
Output: [1, 1]
Explanation: LCM of 1 and 1 is 1, while their GCD is 1.

Constraints:
1 ≤ a, b ≤ 104

Expected Complexities
Time Complexity: O(log(min(a, b))
Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> lcmAndGcd(int a, int b) {
    // code here
    vector<int> res;
    int p = a;
    int q = b;

    while (q != 0) {
      int temp = q;
      q = p % q;
      p = temp;
    }

    int gcd = p;

    int lcm = (a * b) / gcd;

    res.push_back(lcm);
    res.push_back(gcd);

    return res;
  }
};

int main() { 
    
    Solution sol;

    int a = 324;
    int b = 32;

    vector<int> res = sol.lcmAndGcd(a, b);

    for(int i: res){
        cout << i << " ";
    }

    return 0; 
}