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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                s += "#,"; 
            } else {
                s += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (getline(ss, item, ',')) {
                if (item != "#") {
                    curr->left = new TreeNode(stoi(item));
                    q.push(curr->left);
                }
            }

            if (getline(ss, item, ',')) {
                if (item != "#") {
                    curr->right = new TreeNode(stoi(item));
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};
