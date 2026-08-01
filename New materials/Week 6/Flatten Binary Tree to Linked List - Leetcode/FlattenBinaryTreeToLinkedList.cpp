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
    void preorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if(!root) {
            return;
        }

        nodes.push_back(root);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        preorder(root, nodes);

        for(int i = 0; i + 1 < nodes.size(); ++i) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }

        if(!nodes.empty()) {
            nodes.back()->left = nullptr;
            nodes.back()->right = nullptr;
        }
    }
};
