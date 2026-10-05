/*
204. Count Primes

Medium

Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0

Constraints:
0 <= n <= 5 * 106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {

        vector<bool> v(n + 1, true);

        for (int i = 2; i * i <= n; i++) {
            if (v[i] == true) {
                for (int j = i * i; j <= n; j += i) {
                    v[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (v[i]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    
    Solution sol;

    cout << sol.countPrimes(23);

    return 0;
}