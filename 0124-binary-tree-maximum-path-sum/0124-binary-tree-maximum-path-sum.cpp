/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxSum = INT_MIN;

    int getMaxGain(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Calculate max path sum for left and right subtrees.
        // We use std::max(0, ...) to ignore negative paths since they lower the sum.
        int leftGain = std::max(0, getMaxGain(root->left));
        int rightGain = std::max(0, getMaxGain(root->right));

        // Price of the full path passing THROUGH the current node as the highest point (an inverted V)
        int currentPathSum = root->val + leftGain + rightGain;

        // Update global maximum path sum
        maxSum = std::max(maxSum, currentPathSum);

        // Return the maximum single-branch path sum to the parent node
        return root->val + std::max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        getMaxGain(root);
        return maxSum;
    }
};