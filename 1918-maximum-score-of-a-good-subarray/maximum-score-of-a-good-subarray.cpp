class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l=k,r=k;
        int val=nums[k];
        int ans=nums[k];
        while(l>0 || r<nums.size()-1){
            if(l<=0 || (r<nums.size()-1 && nums[r+1]>nums[l-1])) r++;
            else l--;
            val=min(val,min(nums[l],nums[r]));
            ans=max(ans,val*(r-l+1));
            // cout<<l<<" "<<r<<" "<<val<<" "<<val*(r-l+1)<<"\n";
        }
        return ans;
    }
};