class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            int n=target-nums[i];
            if(mp.find(n) != mp.end() && mp[n]!=i){
                return {i,mp[n]};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};