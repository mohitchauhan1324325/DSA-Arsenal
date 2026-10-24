/*
All Divisors of Number

Difficulty: Easy

Given an integer n, return all the divisors of n in the ascending order.

Examples:

Input : n = 20
Output: 1 2 4 5 10 20
Explanation: 20 is completely divisible by 1, 2, 4, 5, 10 and 20.

Input: n = 21191
Output: 1 21191
Explanation: As 21191 is a prime number, it has only 2 factors(1 and the number
itself).

Constraints:
1 ≤ n ≤ 109

Expected Complexities
Time Complexity: O(sqrt(n))
Auxiliary Space: O(sqrt(n))
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getDivisors(int n) {
    // code here
    vector<int> res;

    for (int i = 1; i * i <= n; i++) {

      if (n % i == 0) {
        res.push_back(i);

        if (i != n / i) {
          res.push_back(n / i);
        }
      }
    }

    sort(res.begin(), res.end());

    return res;
  }
};

int main() { 

    Solution sol;

    vector<int> res = sol.getDivisors(20);

    for(int i: res){
        cout << i << " ";
    }

    return 0; 
}