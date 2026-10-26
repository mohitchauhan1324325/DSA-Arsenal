/*
Sum of all Submatrices of a Given Matrix

Difficulty: Medium

Given a n * n 2D matrix, the task to find the sum of all the submatrices.

Examples:

Input :  mat[][] = [[1, 1],
                    [1, 1]];
Output : 16
Explanation:
Number of sub-matrices with 1 elements = 4
Number of sub-matrices with 2 elements = 4
Number of sub-matrices with 3 elements = 0
Number of sub-matrices with 4 elements = 1

Since all the entries are 1, the sum becomes
sum = 1 * 4 + 2 * 4 + 3 * 0 + 4 * 1 = 16


Input : mat[][] = [[1, 2, 3],
                    [4, 5, 6],
                    [7, 8, 9]]
Output : 500

*/

/*
[Expected Approach] Using Reverse Lookup - O(n^2) Time and O(1) Space


The idea is to calculate the contribution of each element to the total sum by
determining in how many different submatrices that element appears. We can
directly compute how many submatrices contain each element in O(1) time and use
this to find each element's total contribution to the sum.

Step by step approach:

• For each element at position (i ,j), calculate how many different top-left
• corners could form a submatrix containing it: (i+1)*(j+1). 
• Calculate how many different bottom-right corners could form a submatrix containing it: (n-i)*(n-j). 
• The total number of submatrices containing this element is the product: (i + 1)(j + 1)(n - i)*(n - j). 
• Multiply this count by the element's value to get its total contribution to the sum. 


Illustration:

Taking example of matrix:
[1 2 3]
[4 5 6]
[7 8 9]

Let's consider the element 5 at position (1,1) in a 3×3 matrix:

• Possible top-left corners: (0,0), (0,1), (1,0), (1,1) → (1+1)*(1+1) = 4 possibilities 
• Possible bottom-right corners: (1,1), (1,2), (2,1), (2,2) → (3-1)*(3-1) = 4 possibilities 
• Total submatrices containing 5: 4×4 = 16 submatrices 
• Total contribution of element 5 to the sum: 5×16 = 80

*/
#include <iostream>
#include <vector>
using namespace std;

// Function to find the sum of all submatrices
int matrixSum(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int res = 0;

  // Iterate through each element in the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      // Number of ways to choose the top-left corner
      int topLeft = (i + 1) * (j + 1);

      // Number of ways to choose the bottom-right corner
      int bottomRight = (n - i) * (n - j);

      // Calculate contribution of current element
      res += (topLeft * bottomRight * matrix[i][j]);
    }
  }

  return res;
}

int main() {
  vector<vector<int>> matrix = {{1, 1}, {1, 1}};

  cout << matrixSum(matrix);
  return 0;
}