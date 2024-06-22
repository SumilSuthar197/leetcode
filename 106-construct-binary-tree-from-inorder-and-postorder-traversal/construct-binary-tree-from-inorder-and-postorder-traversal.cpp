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
    TreeNode* buildingTree(const vector<int>& postorder, int ps, int pe,
                           const vector<int>& inorder, int is, int ie,
                           unordered_map<int, int>& mp) {
        if (ps > pe || is > ie)
            return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);
        int index = mp[root->val];
        root->left = buildingTree(postorder, ps, ps + index - is - 1, inorder,
                                  is, index - 1, mp);
        root->right = buildingTree(postorder, ps + index - is, pe - 1, inorder,
                                   index + 1, ie, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = buildingTree(postorder, 0, postorder.size() - 1,
                                      inorder, 0, inorder.size() - 1, mp);
        return root;
    }
};