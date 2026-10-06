/*
Aggressive Cows

Difficulty: Medium

Given an integer array arr[], which denotes the positions of stalls. All the
positions are distinct. There are k aggressive cows. Assign the cows to the
stalls such that the minimum distance between any two cows is maximized.

Examples:

Input: arr[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at arr[0], the second at arr[2], and
the third at arr[3]. The minimum distance between any two cows is 3 (between
arr[0] and arr[2]), which is the maximum possible among all valid arrangements.

Input: arr[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at arr[0], the second at arr[1], and
the third at arr[4]. In this arrangement, the minimum distance between any two
cows is 4 (between arr[1] and arr[4]), which is the maximum possible among all
valid arrangements. Constraints:

arr.size() ≤ 106
0 ≤ arr[i] ≤ 108
2 ≤ k ≤ arr.size()

Expected Complexities
Time Complexity: O(n log m)
Auxiliary Space: O(1)
*/

class Solution {
public:
  int aggressiveCows(vector<int> &arr, int k) {
    // code here
    sort(arr.begin(), arr.end());
    int n = arr.size();

    int low = 1;
    int high = arr[n - 1] - arr[0];
    int ans = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      int cows = 1;
      int lastCow = arr[0];
      for (int i = 1; i < n; i++) {
        if (arr[i] - lastCow >= mid) {
          cows++;
          lastCow = arr[i];
        }
      }

      if (cows >= k) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return ans;
  }
};
