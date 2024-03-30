class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0, r = 0, ans = 0;
        unordered_map<int, int> mp;
        for (; r < nums.size(); r++) {
            mp[nums[r]]++;
            for (; mp.size() > k && l <= r; l++) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
            }
            ans += r - l + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};