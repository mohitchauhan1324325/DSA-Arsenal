/*
Kth smallest element in the array using constant space when array can't be
modified

Given an array arr[] of size N having no duplicates and an integer K,
the task is to find the Kth smallest element from the array in constant extra
space and the array can't be modified.

Examples:

Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3
Output: 7
Given array in sorted is {3, 4, 7, 10, 15, 20}
where 7 is the third smallest element.

Input: arr[] = {12, 3, 5, 7, 19}, K = 2
Output: 5


Approach: First we find the min and max elements from the array. Then we set low
= min, high = max and mid = (low + high) / 2. Now, perform a modified binary
search, and for each mid we count the number of elements less than mid and equal
to mid. If countLess < k and countLess + countEqual ? k then mid is our answer,
else we have to modify our low and high.

Time Complexity: O(N log(Max - Min)) where Max and Min are the maximum and
minimum elements from the array respectively and N is the size of the array.
Auxiliary Space: O(1), no extra space is required, so it is a constant.
*/

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int *arr, int k, int n) {

  // Minimum and maximum element from the array
  int low = *min_element(arr, arr + n);
  int high = *max_element(arr, arr + n);

  // Modified binary search
  while (low <= high) {

    int mid = low + (high - low) / 2;

    // To store the count of elements from the array
    // which are less than mid and
    // the elements which are equal to mid
    int countless = 0, countequal = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i] < mid)
        ++countless;
      else if (arr[i] == mid)
        ++countequal;
    }

    // If mid is the kth smallest
    if (countless < k && (countless + countequal) >= k) {
      return mid;
    }

    // If the required element is less than mid
    else if (countless >= k) {
      high = mid - 1;
    }

    // If the required element is greater than mid
    else if (countless < k && countless + countequal < k) {
      low = mid + 1;
    }
  }
}

// Driver code
int main() {
  int arr[] = {7, 10, 4, 3, 20, 15};
  int n = sizeof(arr) / sizeof(int);
  int k = 3;

  cout << kthSmallest(arr, k, n);

  return 0;
}