class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count = 0;
        int maxEle = *max_element(nums.begin(), nums.end());
        int maxFreq = 0, n = nums.size(), l = 0, r = 0;

        for (; r < n; r++) {
            if (nums[r] == maxEle)
                maxFreq++;
            while (maxFreq >= k) {
                count+=n-r;
                if (nums[l] == maxEle)
                    maxFreq--;
                l++;
            }
        }

        return count;
    }
};