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
    unordered_map<int,int> pos;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int left, int right) {

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (left == right) {
            return root;
        }

        if (left > right) {
            return nullptr;
        }

        int leftRoot = preorder[preIndex];

        int idx = pos[leftRoot];

        root->left = build(preorder, postorder, left, idx);

        if (idx + 1 <= right - 1) {
            root->right = build(preorder, postorder, idx + 1, right - 1);
        }

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        for (int i = 0; i < postorder.size(); i++) {
            pos[postorder[i]] = i;
        }

        return build(preorder, postorder, 0, postorder.size() - 1);
    }
};
