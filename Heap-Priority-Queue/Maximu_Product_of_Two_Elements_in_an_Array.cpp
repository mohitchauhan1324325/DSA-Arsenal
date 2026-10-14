/*
Maximum Product of Two Elements in an Array

Easy

You are given an array of integers nums.
Choose two different indices i and j of that array.
Return the maximum value of (nums[i] - 1) * (nums[j] - 1).


Example 1:
Input: nums = [3,4,5,2]
Output: 12
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will
get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4
= 12.

Example 2:
Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the
maximum value of (5-1)*(5-1) = 16.

Example 3:
Input: nums = [3,7]
Output: 12


Constraints:
2 <= nums.length <= 500
1 <= nums[i] <= 10^3


Time Complexity: (O(n log n))
Space Complexity: (O(n))
*/

class Solution {
public:
  int maxProduct(vector<int> &nums) {

    priority_queue<int> pq;

    for (int i : nums) {
      pq.push(i);
    }

    int m1 = pq.top();
    pq.pop();

    int m2 = pq.top();
    pq.pop();

    int ans = (m1 - 1) * (m2 - 1);

    return ans;
  }
};