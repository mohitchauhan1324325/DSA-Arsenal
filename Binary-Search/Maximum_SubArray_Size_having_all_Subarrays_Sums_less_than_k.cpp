/*
Maximum subarray size having all subarrays sums less than k

Given an array of positive integers arr[] of size n, and an integer k. The task
is to find the maximum subarray size such that all subarrays of that size have
sum less than or equals to k.

Examples :

Input :  arr[] = [1, 2, 3, 4], k = 8.
Output : 2
Explanation: Following are the sum of subarray of size 1 to 4.

Sum of subarrays of size 1: 1, 2, 3, 4.
Sum of subarrays of size 2: 3, 5, 7.
Sum of subarrays of size 3: 6, 9.
Sum of subarrays of size 4: 10.
So, maximum subarray size such that all subarrays of that size have the sum of
elements less than 8 is 2.

Input:  arr[] = [1, 2, 10, 4], k = 8.
Output : -1
Explanation: There is an array element (10) with value greater than k, so
subarray sum cannot be less than k.

Input :  arr[] = [1, 2, 10, 4], k = 14
Output : 2
*/

/*
[Naive Approach] - Using Nested Loops - O(n ^ 3) Time and O(1) Space

The idea is to generate all possible subarrays of all sizes and find sum of
their elements. To do so, use three nested loops, where the outer most loops
marks the size of the subarray, the middle loop marks the starting index of the
subarray, and the inner loops marks the last index of the subarray.

For any integer x in range [1, n], if all the subarrays of array arr[] of size
x, has sum of there elements less than or equals to k, store the value x in
answer and move to x + 1. At last print the result.
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySize(vector<int> &arr, int k) {
  int n = arr.size();

  // to store the answer
  int ans = -1;

  // generate all possible subarrays
  for (int i = 1; i <= n; i++) {

    // to store the max sum of all
    // possible subarrays of size i
    int maxSum = INT_MIN;

    for (int j = 0; j < n - i + 1; j++) {

      // calculate the sum of the subarray
      int sum = 0;
      for (int l = j; l < j + i; l++) {
        sum += arr[l];
      }

      // update the max sum
      maxSum = max(maxSum, sum);
    }

    // if the maxSum is less than or equals to k
    if (maxSum <= k) {
      ans = max(ans, i);
    }
  }

  return ans;
}

int main() {
  vector<int> arr = {1, 2, 3, 4};
  int k = 8;
  cout << maxSubarraySize(arr, k) << endl;
  return 0;
}

/*
[Better Approach] - Using Binary Search and Sliding Window - O(n * log n) Time
and O(1) Space

It can be observed that if for any integer x, all subarrays of size x have the
sum of there elements less than or equals to k, then x - 1 will also satisfy the
condition. Similarly, if x does not satisfy the condition then x + 1 will also
not work. Thus we can apply binary search in range 1 to n, to find the max
integer x that satisfies the required condition. 

Follow the below given steps to solve the problem:

# Create two counters, low and high, and set their values to 1 and n respectively.
# Now run a loop until low <= high
# In each iteration, find the mid of low and high, i.e. (low + high) / 2
# Now using sliding window approach, find the maximum possible sum of a subarray  
  of size mid. 
# If maxSum <= k, then set low = mid + 1, as we can increase the size
  of subarray. 
# Else, if maxSum > k, then set high = mid - 1, as we need to reduce
  the size of subarray. 
# The loop breaks when low > high, and high stores the final
  result.

*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySize(vector<int> &arr, int k) {
    int n = arr.size();

    // initialize the low and high pointers
    int low = 1, high = n;

    // perform binary search 
    while(low <= high) {
        int mid = low + (high - low) / 2;

        // to store the sum of the subarray
        int sum = 0;

        // to store the max sum of all 
        // possible subarrays of size mid
        int maxSum = INT_MIN;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(i >= mid) {
                sum -= arr[i - mid];
            }

            if(i >= mid - 1) {
                maxSum = max(maxSum, sum);
            }
        }

        if(maxSum <= k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(high == 0)
        return -1;
    return high;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 8;
    cout << maxSubarraySize(arr, k) << endl;
    return 0;
}

/*
[Expected Approach] - Using Sliding Window - O(n) Time and O(1) Space

The approach is to find the minimum subarray size whose sum is greater than integer k.  Out result will be this window size - 1.

# Create two counters, start and end, to store the starting and ending point of the current subarray.
# Also create two variables, sum and minLen, to store the sum of current subarray and the minimum length of subarray with sum of its elements greater than k respectively.
# Initialize start and end with 0
# Now, run a loop until end < n, and in each iteration add arr[end] to sum and increment end by 1.
# While sum > k, store the minimum of minLen and end - start, subtract arr[start] from sum, and increment start by 1.
# The loop breaks when end >= n, and minLen - 1 is the final answer.

*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySize(vector<int> &arr, int k) {
    int n = arr.size();

    // to store the start and end 
    // point of the subarray
    int start = 0, end = 0;

    // to store the sum of subarray
    int sum = 0;

    // to store the minimum size of
    // subarray with sum greater than k
    int minLen = n + 1;

    // using sliding window technique
    // to find the subarray
    while(end < n) {

        // add the current element to the sum
        // and increase the end pointer
        sum += arr[end];
        end++;

        // if the sum is greater than k
        while(sum > k) {
            minLen = min(minLen, end - start);
            sum -= arr[start];
            start++;
        }
    }

    int ans = minLen - 1;

    if(ans == 0)
        return -1;
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 8;
    cout << maxSubarraySize(arr, k) << endl;
    return 0;
}