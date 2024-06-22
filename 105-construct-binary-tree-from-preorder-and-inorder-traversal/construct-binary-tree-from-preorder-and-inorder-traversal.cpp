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
    TreeNode* buildingTree(const vector<int>& preorder, int ps, int pe,
                           const vector<int>& inorder, int is, int ie,
                           unordered_map<int, int>& mp) {
        if (ps > pe || is > ie)
            return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int temp = mp[preorder[ps]];

        root->left = buildingTree(preorder, ps + 1, ps + temp - is, inorder, is,
                                  temp - 1, mp);
        root->right = buildingTree(preorder, ps + temp - is + 1, pe, inorder,
                                   temp + 1, ie, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = buildingTree(preorder, 0, preorder.size() - 1, inorder,
                                      0, inorder.size() - 1, mp);
        return root;
    }
};