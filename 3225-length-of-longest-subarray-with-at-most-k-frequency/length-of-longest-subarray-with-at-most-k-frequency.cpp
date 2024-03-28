class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, c = 0, n = nums.size();
        unordered_map<int, int> mp;
        for (; r < n; r++) {
            mp[nums[r]]++;
            for (; mp[nums[r]] > k; l++) {
                mp[nums[l]]--;
            }
            c = max(c, r - l + 1);
        }
        return c;
    }
};