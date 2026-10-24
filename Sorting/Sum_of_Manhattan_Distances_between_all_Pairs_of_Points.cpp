/*
Sum of Manhattan distances between all pairs of points

Given n integer coordinates. The task is to find the sum of the Manhattan
distance between all pairs of coordinates. Manhattan Distance between (x1, y1)
and (x2, y2) is: |x1 - x2| + |y1 - y2|

Examples :
Input : n = 4, p1 = { -1, 5 }, p2 = { 1, 6 }, p3 = { 3, 5 }, p4 = { 2, 3 }
Output : 22
Explanation :
Distance of { 1, 6 }, { 3, 5 }, { 2, 3 } from { -1, 5 } are 3, 4, 5
respectively. Therefore, sum = 3 + 4 + 5 = 12. Distance of { 3, 5 }, { 2, 3 }
from { 1, 6 } are 3, 4 respectively. Therefore, sum = 12 + 3 + 4 = 19 Distance
of { 2, 3 } from { 3, 5 } is 3. Therefore, sum = 19 + 3 = 22.

*/

/*
Naive Approach - Using Nested Loops - O(n^2) Time and O(1) Space

The idea is to use two loops: the outer loop picks a point, and the inner loop
calculates the Manhattan distance between that point and all other points.
*/

#include <bits/stdc++.h>
using namespace std;

int distancesum(int x[], int y[], int n) {
  int sum = 0;

  // for each point, finding distance to
  // rest of the point
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      sum += (abs(x[i] - x[j]) + abs(y[i] - y[j]));
  return sum;
}

int main() {
  int x[] = {-1, 1, 3, 2};
  int y[] = {5, 6, 5, 3};
  int n = sizeof(x) / sizeof(x[0]);
  cout << distancesum(x, y, n) << endl;
  return 0;
}

/*
Expected Approach - Using Greedy Approach - O(n log n) Time and O(1) Space

The idea for this approach is to decompose the Manhattan distance into two
independent sums, one for the difference between x coordinates and the second
between y coordinates. Let’s assume we’ve already calculated the sum of
distances between points up to xi−1​, and this sum is denoted as res. Now,
to include the next point xi, we need to compute the distance between xi and all
previous points xk (where xk<xi).

The sum of distances for all pairs including xi​ will be:

res = res + (xi - x0) + (xi - x1) + (xi - x2) + (xi - x3).........(xi - xi-1)
res = res + (xi)*i - (x0 +x1 + x2 + ...... xi-1) , because in a sorted array,
there are i elements smaller than the current index i .

res = res + (xi)*i - Sxi-1  , where Sxi-1 is the sum of the values of x axis for
all the previous points till index i - 1.

Similarly for y Axis
res = res + (yi)*i - Syi-1  , where Syi-1 is the sum of the values of y axis for
all the previous points till index i - 1.

By repeating the above process for all points(xi), we get the sum of Manhattan
distances between all pairs of points
*/

#include <bits/stdc++.h>
using namespace std;

int distancesum(vector<int> arr, int n) {
  // sorting the array.
  sort(arr.begin(), arr.end());

  // for each point, finding the distance.
  int res = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    res += (arr[i] * i - sum);
    sum += arr[i];
  }

  return res;
}

int totaldistancesum(vector<int> x, vector<int> y, int n) {
  // Adding the distances along x and y axis.
  return distancesum(x, n) + distancesum(y, n);
}

int main() {
  vector<int> x = {-1, 1, 3, 2};
  vector<int> y = {5, 6, 5, 3};
  int n = x.size();
  cout << totaldistancesum(x, y, n) << endl;
  return 0;
}