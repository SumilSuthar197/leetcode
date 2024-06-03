class Solution {
public:
    void combination(int start, int target, vector<int> arr,
                     vector<vector<int>>& ans, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < arr.size(); i++) {
            if (i > start && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            temp.push_back(arr[i]);
            combination(i + 1, target - arr[i], arr, ans, temp);
            temp.pop_back();
        }
    }

    // Time Complexity: 2^n * k, where k be the average length of subset and n is the length of array.
    // Space Complexity: k*x, , where x be the number of subsets in the ans set
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combination(0, target, candidates, ans, temp);
        return ans;
    }
};