/*
Duplicates in Limited Range Array

Difficulty: Easy

Given an array arr[] of size n, containing elements from the range 1 to n, and
each element appears at most twice, return an array of all the integers that
appears twice. Note: You can return the elements in any order but the driver
code will print them in sorted order.

Examples:

Input: arr[] = [2, 3, 1, 2, 3]
Output: [2, 3]
Explanation: 2 and 3 occur more than once in the given array.

Input: arr[] = [3, 1, 2]
Output: []
Explanation: There is no repeating element in the array, so the output is empty.

Constraints:
1 ≤ arr.size() ≤ 106
arr[i] ≤ arr.size()

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

class Solution {
public:
  vector<int> findDuplicates(vector<int> &arr) {
    // code here
    vector<int> ans;

    for (int x : arr) {

      int idx = abs(x) - 1;

      if (arr[idx] < 0) {
        ans.push_back(abs(x));
      } else {
        arr[idx] = -arr[idx];
      }
    }

    return ans;
  }
};
