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

// BFS Without Processing Levels Separately
// BFS + Depth Tracking

int maxDepth(TreeNode *root) {
  if (root == nullptr)
    return 0;

  queue<pair<TreeNode *, int>> q;
  q.push({root, 1});

  int depth = 0;

  while (!q.empty()) {

    auto [node, currDepth] = q.front();
    q.pop();

    depth = max(depth, currDepth);

    if (node->left)
            q.push({node->left, currDepth + 1);

        if (node->right)
          q.push({node->right, currDepth + 1});
    }

    return depth;
  }