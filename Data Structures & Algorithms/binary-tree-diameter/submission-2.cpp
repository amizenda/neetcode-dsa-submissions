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
public:
    int maxDiameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        calculateDepth(root);
        return maxDiameter;
    }

    int calculateDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = calculateDepth(root->left);
        int right = calculateDepth(root->right);

        maxDiameter = max(maxDiameter, right + left);

        return max(right, left) + 1;
    }
};
