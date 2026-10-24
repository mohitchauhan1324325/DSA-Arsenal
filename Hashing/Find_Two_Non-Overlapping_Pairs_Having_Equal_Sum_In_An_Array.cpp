/*
Find two non-overlapping pairs having equal sum in an Array

Given an unsorted array of integers. The task is to find any two non-overlapping
pairs whose sum is equal. Two pairs are said to be non-overlapping if all the
elements of the pairs are at different indices. That is, pair (Ai, Aj) and pair
(Am, An) are said to be non-overlapping if i ? j ? m ? n.

Examples:

Input: arr[] = {8, 4, 7, 8, 4}
Output: Pair First(4, 8)
        Pair Second (8, 4)

Input: arr[] = {8, 4, 7, 4}
Output: No such non-overlapping pairs present.

Note: (8, 4) and (8, 4) forms overlapping pair
as index of 8 is same in both pairs.
The idea is to use a map of key-value pair to store all occurrences of a sum.
The key in the map will store the sum and the corresponding value will be a list
of pair of indices (i, j) with that sum.

The idea is to traverse the array and generate all possible pairs.
If a new sum is found, insert it directly to the map otherwise check if any of
the previously encountered pairs with that sum does not overlap with current
pair. If not, print both of the pairs.

Time Complexity: O(n2)
Auxiliary Space: O(n2)

*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef pair<int, int> Pair;

// Function to find two non-overlapping
// with same sum in an array
void findPairs(int arr[], int n) {
  // first create an empty map
  // key -> which is sum of a pair of
  // elements in the array
  // value -> vector storing index of
  // every pair having that sum
  unordered_map<int, vector<Pair>> map;

  // consider every pair (arr[i], arr[j])
  // and where (j > i)
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {

      // calculate sum of current pair
      int sum = arr[i] + arr[j];

      // if sum is already present in the map
      if (map.find(sum) != map.end()) {

        // check every pair having equal sum
        for (auto pair : map.find(sum)->second) {
          int m = pair.first, n = pair.second;

          // if pairs don't overlap,
          // print them and return
          if ((m != i && m != j) && (n != i && n != j)) {
            cout << "Pair First(" << arr[i] << ", " << arr[j]
                 << ")\nPair Second (" << arr[m] << ", " << arr[n] << ")";
            return;
          }
        }
      }

      // Insert current pair into the map
      map[sum].push_back({i, j});
    }
  }

  // If no such pair found
  cout << "No such non-overlapping pairs present";
}

// Driver Code
int main() {
  int arr[] = {8, 4, 7, 8, 4};
  int size = sizeof(arr) / sizeof(arr[0]);

  findPairs(arr, size);

  return 0;
}