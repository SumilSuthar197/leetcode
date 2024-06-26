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
class Solution {
public:
    void traversal(TreeNode* root, int& k, int& c) {
        if (root == NULL)
            return;
        traversal(root->left, k, c);
        if (k-- == 1)
            c = root->val;
        traversal(root->right, k, c);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        traversal(root, k, c);
        return c;
    }
};