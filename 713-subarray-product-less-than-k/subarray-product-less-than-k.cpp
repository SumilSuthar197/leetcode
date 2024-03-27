class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int c = 0, l = 0, r = 0, temp = 1, n = nums.size();

        for (; r < n; r++) {
            temp *= nums[r];
            for (; l <= r && temp >= k; l++)
                temp /= nums[l];
            c += 1 + (r - l);
        }
        return c;
    }
};