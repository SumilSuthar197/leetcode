class Solution {
public:
    int atMost(vector<int> nums,int k){
        int l=0,r=0,ans=0;

        for(;r<nums.size();r++){
            k-=nums[r]%2;
            for(;k<0;l++){
                k+=nums[l]%2;
            }
            ans+=r-l+1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++) nums[i]%=2;
        // odd=1, even=0
        // Now question is find subarray where sum is k;
        //Method 1: Prefix Sum + Hashing

        // unordered_map<int,int> mp;
        // int sum=0,c=0,l=0,r=0;
        // mp[0]=1;
        // for(;r<nums.size();r++){
        //     sum+=nums[r];
        //     if(mp.count(sum-k)){
        //         c+=mp[sum-k];
        //     }
        //     mp[sum]++;
        // }
        // return c;

        //Method 2:
        return atMost(nums,k)-atMost(nums,k-1);
    }
};