class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        int a,b;
        for(int i:nums) mp[i]++;
        for(int i=1;i<=nums.size();i++){
            mp[i]--;
            if(mp[i]==1) a=i;
            if(mp[i]==-1) b=i;
        }
        return {a,b};
    }
};