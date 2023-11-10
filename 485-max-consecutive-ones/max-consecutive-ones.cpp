class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,ans=0,zero=0;
        for(;j<nums.size();j++){
            if(nums[j]==0) zero++;
            for(;zero!=0;i++){
               if(nums[i]==0) zero--; 
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};