class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long l=0,r=0,ans=0,sum=0;
        sort(nums.begin(),nums.end());
        for(;r<nums.size();r++){
            sum+=nums[r];
            for(;((r-l+1)*nums[r])-sum>k && l<=r;l++){
                sum-=nums[l];
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};