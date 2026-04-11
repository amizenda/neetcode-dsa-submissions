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
private:
    int calculateDepth(TreeNode* node) {
        if(!node) return 0;

        int left = calculateDepth(node->left);
        int right = calculateDepth(node->right);

        maxDiameter = max(maxDiameter, right + left);

        return max(left, right) + 1;
    }
};
