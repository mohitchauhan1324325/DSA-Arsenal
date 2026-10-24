/*
Largest Prime Factor

Difficulty: Medium

Given a number n, your task is to find the largest prime factor of n.

Examples:

Input: n = 5
Output: 5
Explanation: The prime factorization of 5 is just 5. Therefore, the largest prime factor is 5.

Input: n = 24
Output: 3
Explanation: The prime factorization of 24 is 23×3. Among the prime factors (2, 3), the largest is 3.

Input: n = 13195
Output: 29
Explanation: The prime factorization of 13195 is 5×7×13×29. The largest prime factor is 29.

Constraints:
2 ≤ n ≤ 109

Expected Complexities
Time Complexity: O(sqrt(n))
Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int largestPrimeFactor(int n) {
		// code here
		int ans = 1;
		
		while(n % 2 == 0){
		    ans = 2;
		    n /= 2;
		}
		
		for(int i = 3; i * i <= n; i += 2){
		    while(n % i == 0){
		        ans = i;
		        n /= i;
		    }
		}
		
		if(n > 2){
		    ans = n;
		}
		
		return ans;
	}
};


int main() {
    
    Solution sol;

    cout << sol.largestPrimeFactor(321);
    
    return 0;
}