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
    TreeNode* first = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        // here main logic comes
        if (prev != NULL && prev->val > root->val) {
            if (first == NULL)
                first = prev;
            last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
    }
};