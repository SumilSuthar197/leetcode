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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int x = temp.second.first;
            int y = temp.second.second;
            mp[x][y].insert(temp.first->val);
            if (temp.first->left != NULL)
                q.push({temp.first->left, {x - 1, y + 1}});
            if (temp.first->right != NULL)
                q.push({temp.first->right, {x + 1, y + 1}});
        }

        for (auto i : mp) {
            vector<int> v;
            for (auto j : i.second) {
                v.insert(v.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};