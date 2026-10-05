/*
Palindrome Digit Sum

Difficulty: Basic

Given a number n. Return true if the digit sum(or sum of digits) of n is a Palindrome number otherwise false.
A Palindrome number is a number that stays the same when reversed

Examples:

Input: n = 56
Output: true
Explanation: The digit sum of 56 is 5+6 = 11. Since, 11 is a palindrome number.Thus, answer is true.

Input: n = 98
Output: false
Explanation: The digit sum of 98 is 9+8 = 17. Since 17 is not a palindrome,thus, answer is false.

Constraints:
1 ≤ n ≤ 109

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    bool isDigitSumPalindrome(int n) {
        // code here
        int sum = 0;
        
        while(n > 0){
            sum += n % 10;
            n /= 10;
        }
        
        int original = sum;
        int rev = 0;
        
        while(sum > 0){
            rev = rev * 10 + sum % 10;
            sum /= 10;
        }
        
        return original == rev;
    }
};

int main() {
    
    Solution sol;

    cout << (sol.isDigitSumPalindrome(56) ? "True" : "False");

    return 0;
}