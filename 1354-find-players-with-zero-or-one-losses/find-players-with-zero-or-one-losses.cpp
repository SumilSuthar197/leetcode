class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto i:matches){
            mp[i[1]]++;
            if(mp.find(i[0])==mp.end()) mp[i[0]]=0;
        }
        vector<vector<int>> ans(2,vector<int>{});
        for(auto it:mp){
            if(it.second==0){
                ans[0].push_back(it.first);
            }
            else if(it.second==1){
                ans[1].push_back(it.first);
            }
        }
        return ans;
    }
};