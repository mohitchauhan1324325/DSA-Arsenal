/*
Allocate Minimum Pages

Difficulty: Medium

Given an array arr[] of integers, where each element arr[i] represents the
number of pages in the i-th book. You also have an integer k representing the
number of students. The task is to allocate books to each student such that:

- Each student receives atleast one book.
- Each student is assigned a contiguous sequence of books.
- No book is assigned to more than one student.
- All books must be allocated.

The objective is to minimize the maximum number of pages assigned to any
student. In other words, out of all possible allocations, find the arrangement
where the student who receives the most pages still has the smallest possible
maximum. If it is not possible to allocate books to all students, return -1;


Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.

Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to
allocate a book to each student.


Constraints:

1 ≤ arr.size() ≤ 106
1 ≤ arr[i], k ≤ 104


Time Complexity: O( n × log(sum(arr)))
Auxiliary Space: O(1)


Topics:
Searching, Divide and Conquer

*/

class Solution {
public:
  bool isValid(vector<int> &arr, int n, int k, long long maxPages) {
    long long sum = 0;
    int student = 1;

    for (int i = 0; i < n; i++) {

      if (sum + arr[i] > maxPages) {
        student++;
        sum = arr[i];
      } else {
        sum += arr[i];
      }

      if (student > k) {
        return false;
      }
    }

    return true;
  }

  int findPages(vector<int> &arr, int k) {
    int n = arr.size();

    if (k > n)
      return -1;

    long long low = *max_element(arr.begin(), arr.end());

    long long high = 0;

    for (int i = 0; i < n; i++) {
      high += arr[i];
    }

    long long res = -1;

    while (low <= high) {
      long long mid = low + (high - low) / 2;

      if (isValid(arr, n, k, mid)) {
        res = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return (int)res;
  }
};
