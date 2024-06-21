/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        // STEP 1: mapping children nodes parent
        mapParent(root, mp);

        // STEP 2: again traveling to find nodes
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        int curr_level = 0;
        q.push(target);
        visited[target] = true;
        while (!q.empty()) {
            int size = q.size();
            if (curr_level == k)
                break;
            curr_level++;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (mp[curr] && !visited[mp[curr]]) {
                    q.push(mp[curr]);
                    visited[mp[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};