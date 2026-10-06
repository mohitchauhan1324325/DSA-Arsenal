/*
Find First and Last Position of Element in Sorted Array

Medium

Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

Time Complexity:  O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
  int fp(vector<int> &nums, int target) {

    int start = 0;
    int end = nums.size() - 1;

    int position = -1;

    while (start <= end) {

      int mid = start + (end - start) / 2;

      if (target == nums[mid]) {
        end = mid - 1;
        position = mid;
      } else if (nums[mid] < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return position;
  }

  int lp(vector<int> &nums, int target) {

    int start = 0;
    int end = nums.size() - 1;

    int position = -1;

    while (start <= end) {

      int mid = start + (end - start) / 2;

      if (target == nums[mid]) {
        start = mid + 1;
        position = mid;
      } else if (nums[mid] < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return position;
  }

  vector<int> searchRange(vector<int> &nums, int target) {

    vector<int> res;

    int first = fp(nums, target);
    int last = lp(nums, target);

    res.push_back(first);
    res.push_back(last);

    return res;
  }
};