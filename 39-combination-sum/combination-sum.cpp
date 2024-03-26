class Solution {
public:
    void combination(int start, int target, vector<int> arr,
                     vector<vector<int>>& ans, vector<int>& temp) {
        if (start == arr.size()) {
            if (target == 0)
                ans.push_back(temp);
            return;
        }

        if (arr[start] <= target) {
            temp.push_back(arr[start]);
            combination(start, target - arr[start], arr, ans, temp);
            temp.pop_back();
        }
        combination(start + 1, target, arr, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(0, target, candidates, ans, temp);
        return ans;
    }
};