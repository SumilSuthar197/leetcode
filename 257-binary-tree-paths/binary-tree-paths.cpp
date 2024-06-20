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
    void getLeafPath(TreeNode* root, vector<int>& temp, vector<string>& ans) {
        if (root == NULL) {
            return;
        }
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            string s = accumulate(
                temp.begin(), temp.end(), string(), [](const string& a, int b) {
                    return a.empty() ? to_string(b) : a + "->" + to_string(b);
                });
            ans.push_back(s);
        }
        getLeafPath(root->left, temp, ans);
        getLeafPath(root->right, temp, ans);
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> temp;
        getLeafPath(root, temp, ans);
        return ans;
    }
};