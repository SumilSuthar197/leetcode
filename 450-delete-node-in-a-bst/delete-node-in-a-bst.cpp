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
    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while (left->right != NULL)
            left = left->right;
        left->right = right;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;
        if (root->val == key)
            return helper(root);

        TreeNode* temp = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                root = root->left;
            } else {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                root = root->right;
            }
        }
        return temp;
    }
};