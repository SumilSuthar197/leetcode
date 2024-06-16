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
    void recursion(TreeNode* root, vector<int>& v, int level) {
        if (root == NULL)
            return;

        if (v.size() == level)
            v.push_back(root->val);
        recursion(root->right, v, level + 1);
        recursion(root->left, v, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recursion(root, ans, 0);
        return ans;
    }
};