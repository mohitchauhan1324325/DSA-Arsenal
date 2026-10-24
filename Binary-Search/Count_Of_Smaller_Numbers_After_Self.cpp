/*
Count of Smaller Numbers After Self

Hard

Given an integer array nums, return an integer array counts where counts[i] is
the number of smaller elements to the right of nums[i].


Example 1:
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:
Input: nums = [-1]
Output: [0]

Example 3:
Input: nums = [-1,-1]
Output: [0,0]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104


Time Complexity: (O(nlog n))
Space Complexity: (O(n))


Topics
Array, Binary Search, Divide and Conquer, Binary Indexed Tree, Segment Tree, Merge Sort, Ordered Set, Treap

*/

class Solution {
public:
  void mergeSort(vector<pair<int, int>> &arr, vector<pair<int, int>> &temp,
                 int left, int right, vector<int> &ans) {

    if (left >= right)
      return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, temp, left, mid, ans);
    mergeSort(arr, temp, mid + 1, right, ans);

    int i = left;
    int j = mid + 1;
    int k = left;
    int smaller = 0;

    while (i <= mid && j <= right) {

      if (arr[j].first < arr[i].first) {
        temp[k++] = arr[j++];
        smaller++;
      } else {
        ans[arr[i].second] += smaller;
        temp[k++] = arr[i++];
      }
    }

    while (i <= mid) {
      ans[arr[i].second] += smaller;
      temp[k++] = arr[i++];
    }

    while (j <= right) {
      temp[k++] = arr[j++];
    }

    for (int x = left; x <= right; x++) {
      arr[x] = temp[x];
    }
  }

  vector<int> countSmaller(vector<int> &nums) {

    int n = nums.size();

    vector<int> ans(n, 0);

    vector<pair<int, int>> arr(n);
    vector<pair<int, int>> temp(n);

    for (int i = 0; i < n; i++) {
      arr[i] = {nums[i], i};
    }

    mergeSort(arr, temp, 0, n - 1, ans);

    return ans;
  }
};