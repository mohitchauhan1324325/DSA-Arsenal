/*
Modify an array such that if 'arr[i]' is 'j' then arr[j] becomes i

Medium

Given an array arr[] of size n, where all elements are distinct and fall within
the range 0 to n-1. The task is to modify arr[] such that if arr[i] = j, then it
gets transformed into arr[j] = i.

Examples:

Input: arr[] = [1, 3, 0, 2]
Output: 2 0 3 1
Explanation: Since arr[0] = 1, update arr[1] to 0
Since arr[1] = 3, update arr[3] to 1
Since arr[2] = 0, update arr[0] to 2
Since arr[3] = 2, update arr[2] to 3

Input: arr[] = [2, 0, 1, 4, 5, 3]
Output: 1 2 0 5 3 4
Explanation: Since arr[0] = 2, update arr[2] to 0
Since arr[1] = 0, update arr[0] to 1
Since arr[2] = 1, update arr[1] to 2
Since arr[3] = 4, update arr[4] to 3
Since arr[4] = 5, update arr[5] to 4
Since arr[5] = 3, update arr[3] to 5

Input: arr[] = [3, 2, 1, 0]
Output: 3 2 1 0
Explanation: Since each element is already at its correct index, the array
remains unchanged.


O(n) Time and O(1) Space

*/

/*

Using Modulo - O(n) Time and O(1) Space
The idea is to store both the old and new values within the same array using
modulo and multiplication. Each element is updated such that arr[arr[i] % n]
accumulates the new position while preserving the original value. After
processing, the new values are extracted by performing integer division with n.
This ensures an in-place transformation without using extra space.

*/

#include <bits/stdc++.h>
using namespace std;

// Rearrange arr[] so that arr[j]
// becomes i if arr[i] is j
void rearrange(vector<int> &arr) {

  int n = arr.size();

  // Store new values using modulo
  for (int i = 0; i < n; i++) {
    arr[arr[i] % n] += i * n;
  }

  // Extract new values
  for (int i = 0; i < n; i++) {
    arr[i] /= n;
  }
}

int main() {

  vector<int> arr = {2, 0, 1, 4, 5, 3};

  rearrange(arr);

  for (int x : arr) {
    cout << x << " ";
  }

  return 0;
}