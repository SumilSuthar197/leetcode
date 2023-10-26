class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,ans=0;
        for(;r<nums.size();r++){
            if(nums[r]==0) k--;
            for(;k<0;l++){
                if(nums[l]==0) k++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};