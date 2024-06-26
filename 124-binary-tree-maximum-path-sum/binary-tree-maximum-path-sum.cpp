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
    int heightTraversal(TreeNode* root, int& maxi) {
        if (root == NULL)
            return 0;
        int ls = max(0, heightTraversal(root->left, maxi));
        int rs = max(0, heightTraversal(root->right, maxi));
        maxi = max(maxi, ls + rs + root->val);

        return root->val + max(ls, rs);
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int maxSum = INT_MIN;
        heightTraversal(root, maxSum);
        return maxSum;
    }
};