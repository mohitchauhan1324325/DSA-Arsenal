/*
Segregate Even and Odd numbers

Difficulty: Basic

Given an array arr, write a program segregating even and odd numbers. The
program should put all even numbers first in sorted order, and then odd numbers
in sorted order.

Note:- You don't need to return the array, you need to modify it in-place.

Example:

Input: arr[] = [12, 34, 45, 9, 8, 90, 3]
Output: [8, 12, 34, 90, 3, 9, 45]
Explanation: Even numbers are 12, 34, 8 and 90. Rest are odd numbers.

Input: arr[] = [0, 1, 2, 3, 4]
Output: [0, 2, 4, 1, 3]
Explanation: 0 2 4 are even and 1 3 are odd numbers.

Input: arr[] = [10, 22, 4, 6]
Output: [4, 6, 10, 22]
Explanation: Here all elements are even, so no need of segregataion

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 105

Expected Complexities
Time Complexity: O(n log n)
Auxiliary Space: O(1)
*/

class Solution {
public:
  void segregateEvenOdd(vector<int> &arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      if (a % 2 == 0 && b % 2 != 0)
        return true;

      if (a % 2 != 0 && b % 2 == 0)
        return false;

      return a < b;
    });
  }
};