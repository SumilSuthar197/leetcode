class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=0;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                n+=mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        return n;
    }
};