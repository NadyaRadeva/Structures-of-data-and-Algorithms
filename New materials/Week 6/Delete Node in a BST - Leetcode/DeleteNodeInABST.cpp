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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return nullptr;
        }

        if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else {
            if(!root->right && !root->left) {
                return nullptr;
            }
            
            if(!root->right) {
                return root->left;
            }

            if(!root->left) {
                return root->right;
            }

            TreeNode* iter = root->right;
            while(iter->left) {
                iter = iter->left;
            }
            root->val = iter->val;
            root->right = deleteNode(root->right, root->val);
        }

        return root;
    }
};
