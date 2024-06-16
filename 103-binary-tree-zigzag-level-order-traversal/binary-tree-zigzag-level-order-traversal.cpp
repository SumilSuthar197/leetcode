/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
 * left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            int l = q.size();
            vector<int> dummy;
            for (int i = 0; i < l; i++) {
                TreeNode* temp = q.front();
                dummy.push_back(temp->val);
                q.pop();
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            if (!flag) {
                reverse(dummy.begin(), dummy.end());
            }
            ans.push_back(dummy);
            flag = !flag;
        }
        return ans;
    }
};