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
    vector<int> sortedValues;

    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left);
        sortedValues.push_back(root->val);
        inorderTraversal(root->right);
    }

    int findLowerBound(int val) {

        int left = 0, right = sortedValues.size() - 1, lowerBoundIndex = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (sortedValues[mid] <= val) {
                lowerBoundIndex = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return lowerBoundIndex;
    }

    int findUpperBound(int val) {

        int left = 0, right = sortedValues.size() - 1, upperBoundIndex = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (sortedValues[mid] >= val) {
                upperBoundIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return upperBoundIndex;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorderTraversal(root);
        vector<vector<int>> result;
        for (int query : queries) {
            int lower = findLowerBound(query);
            int upper = findUpperBound(query);
            int lowerValue = (lower != -1) ? sortedValues[lower] : -1;
            int upperValue = (upper != -1) ? sortedValues[upper] : -1;
            result.push_back({lowerValue, upperValue});
        }
        return result;
    }
};