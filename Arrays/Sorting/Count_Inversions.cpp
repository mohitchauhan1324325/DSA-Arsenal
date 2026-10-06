/*
Count Inversions

Difficulty: Medium

Given an array of integers arr[]. You have to find the Inversion Count of the
array. Inversion count is the number of pairs of elements (i, j) such that i < j
and arr[i] > arr[j].

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4,
3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0 Explanation: As the sequence is
already sorted so there is no inversion count.

Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion
count.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104

Expected Complexities
Time Complexity: O(n log n)
Auxiliary Space: O(n)
*/

class Solution {
public:
  long long merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;

    int i = low;
    int j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= high) {

      if (arr[i] <= arr[j]) {
        temp.push_back(arr[i]);
        i++;
      } else {
        temp.push_back(arr[j]);

        // All remaining elements from i to mid
        // are greater than arr[j]
        count += (mid - i + 1);

        j++;
      }
    }

    while (i <= mid) {
      temp.push_back(arr[i]);
      i++;
    }

    while (j <= high) {
      temp.push_back(arr[j]);
      j++;
    }

    for (int k = low; k <= high; k++) {
      arr[k] = temp[k - low];
    }

    return count;
  }

  long long mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high)
      return 0;

    int mid = low + (high - low) / 2;

    long long count = 0;

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);

    count += merge(arr, low, mid, high);

    return count;
  }

  int inversionCount(vector<int> &arr) {
    return mergeSort(arr, 0, arr.size() - 1);
  }
};