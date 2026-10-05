/*
Count Perfect Squares

Difficulty: Basic

Given a positive integer n, find the number of perfect squares that are less than n in the sample space of perfect squares. The sample space consists of all perfect squares starting from 1 (i.e., 1, 4, 9, 16, 25, …)

Examples :

Input: n = 9
Output: 2
Explanation: 1 and 4 are the only Perfect Squares less than 9. So, the Output is 2.

Input: n = 3
Output: 1
Explanation: 1 is the only Perfect Square less than 3. So, the Output is 1.

Constraints:
1 ≤ n ≤ 108

Expected Complexities
Time Complexity: sqrt(n)
Auxiliary Space: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    int countSquares(int n) {
        // code here
        int sqr = 0;
        for(int i = 1; i < n; i++){
            
            if(i * i < n){
                sqr++;
            }
            else{
                break;
            }
        }
        
        return sqr;
    }
};

int main() {
    
    Solution sol;

    int n = 32;

    int res = sol.countSquares(n);

    cout << res;

    return 0;
}