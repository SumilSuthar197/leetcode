class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int sum=0,c=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>=goal && mp.count(sum-goal)){
                c+=mp[sum-goal];
            }
            mp[sum]++;
        }    
        return c;
    }
};