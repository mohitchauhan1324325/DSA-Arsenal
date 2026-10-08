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

O(n) time
O(w) space

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

// BFS — Level Order

int maxDepth(TreeNode *root) {

  if (root == nullptr)
    return 0;

  queue<TreeNode *> q;
  q.push(root);

  int depth = 0;

  while (!q.empty()) {

    int size = q.size();

    // Process one complete level
    for (int i = 0; i < size; i++) {

      TreeNode *curr = q.front();
      q.pop();

      if (curr->left)
        q.push(curr->left);

      if (curr->right)
        q.push(curr->right);
    }

    depth++;
  }

  return depth;
}