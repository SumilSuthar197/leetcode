class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,last_0=0;
        int ans=0,c=0;
        while(r<nums.size()){
            if(nums[r]==0){
                c++;
                if(c>1){
                    ans=max(ans,r-l-1);
                    l=last_0+1;  
                    c--;
                }
                last_0=r;
            }
            r++;
        }
        if(c<=1) ans=max(ans,r-l-1);
        return ans;
    }
};