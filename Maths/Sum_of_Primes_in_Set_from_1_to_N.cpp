/*
Sum of Primes in Set from 1 to n

Difficulty: Easy

Given a positive integer n, compute and return the sum of all prime numbers between 1 and n (inclusive).

Examples:

Input: n = 5
Output: 10
Explanation: 2, 3 and 5 are prime numbers between 1 and 5(inclusive), and their sum is 2 + 3 + 5 = 10.

Input: n = 10
Output: 17
Explanation: 2, 3, 5 and 7 are prime numbers between 1 and 10(inclusive), and their sum is 2 + 3 + 5 + 7 = 17.

Constraints:
1 ≤ n ≤ 105

Expected Complexities
Time Complexity: O(nloglogn)
Auxiliary Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int prime_Sum(int n) {
		// Code here
		int res = 0;
		
		for (int i = 2; i <= n; i++) {
		    bool isPrime = true;
		    
		    for(int j = 2; j * j <= i; j++){
		        
		        if(i % j == 0){
		          isPrime = false;
		          break;
		        }
		    }
		    
		    if(isPrime){
		        res += i;
		    }
			
		}
		
		return res;
		
	}
};


int main() {
    
    Solution sol;

    int res = sol.prime_Sum(342);

    cout << res;

    return 0;
}