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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        long long ans = 0;
        q.push({root, 0});
        while (!q.empty()) {
            int l = q.size();
            int ml = q.front().second;
            long long first, last;
            for (int i = 0; i < l; i++) {
                auto temp = q.front();
                q.pop();
                if (i == 0)
                    first = temp.second - ml;
                if (i == l - 1)
                    last = temp.second - ml;
                if (temp.first->left != NULL)
                    q.push({temp.first->left, 2 * (temp.second - ml) + 1});
                if (temp.first->right != NULL)
                    q.push({temp.first->right, 2 * (temp.second - ml) + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};