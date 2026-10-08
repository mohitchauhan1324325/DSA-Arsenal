/*
104. Maximum Depth of Binary Tree

Easy

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from
the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

Time:  O(n)
Space: O(1)

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// Morris Traversal for Maximum Depth

class Solution {
public:
  int maxDepth(TreeNode *root) {

    if (root == nullptr)
      return 0;

    TreeNode *curr = root;
    int depth = 0;

    while (curr != nullptr) {

      // No left subtree
      if (curr->left == nullptr) {
        depth++;
        curr = curr->right;
      }

      // Left subtree exists
      else {

        TreeNode *predecessor = curr->left;

        int steps = 1;

        // Find rightmost node of left subtree
        while (predecessor->right != nullptr && predecessor->right != curr) {
          predecessor = predecessor->right;
          steps++;
        }

        // First time visiting curr
        if (predecessor->right == nullptr) {

          predecessor->right = curr;

          depth++;

          curr = curr->left;
        }

        // Returning to curr
        else {

          predecessor->right = nullptr;

          depth -= steps;

          curr = curr->right;
        }
      }
    }

    return depth;
  }
};