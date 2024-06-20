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
    void getLeafPath(TreeNode* root, vector<int>& temp,
                     vector<vector<int>>& ans, int target, int& sum) {
        if (root == NULL) {
            return;
        }
        temp.push_back(root->val);
        sum += root->val;
        if (root->left == NULL && root->right == NULL && sum == target) {
            ans.push_back(temp);
        }
        getLeafPath(root->left, temp, ans, target, sum);
        getLeafPath(root->right, temp, ans, target, sum);
        int a = temp.back();
        temp.pop_back();
        sum -= a;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        getLeafPath(root, temp, ans, targetSum, sum);
        return ans;
    }
};