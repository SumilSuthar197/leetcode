class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> ans;

        for (auto x : nums)  for (auto y : x) m[y]++;

        for (auto x : m) if (x.second == n) ans.push_back(x.first);
  
        sort(ans.begin(), ans.end());
        return ans;
    }
};