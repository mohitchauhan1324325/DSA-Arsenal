/*
Arithmetic Operators

Difficulty: Easy

Given two integer variables x and y, perform the following operations:

p: Addition of x and y
q: Subtraction of y from x
r: Multiplication of x and y
s: Floating-point division of x by y
t: Integer division of x by y
u: Modulo (remainder when x is divided by y)

Examples:

Input: x = 1, y = 2

Output: 3 -1 2 0.500 0 1

Explanation: The given operations are performed:
Addition of x and y = 3
Subtraction of y from x = -1
Multiplication of x and y = 2
Floating-point division of x by y = 0.500
Integer division of x by y = 0
Modulo of x and y = 1
Hence, the output is 3 -1 2 0.500 0 1.

Input: x = 3, y = 4
Output: 7 -1 12 0.750 0 3

Explanation: The given operations are performed.

Constraints:
-100 ≤ x, y ≤ 100
y != 0

Expected Complexities:
Time Complexity: O(1)
Auxiliary Space: O(1)
*/

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  int p = x + y;
  int q = x - y;
  int r = x * y;
  double s = (double)x / y;
  int t = x / y;
  int u = x % y;

  cout << p << " " << q << " " << r << " " << fixed << setprecision(3) << s
       << " " << t << " " << u;

  return 0;
}