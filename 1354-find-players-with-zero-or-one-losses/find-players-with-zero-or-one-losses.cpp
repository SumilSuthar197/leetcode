class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;
        for(int i=0;i<matches.size();i++){
            mp[matches[i][1]]++;
            if(mp.find(matches[i][0])==mp.end()){
                mp[matches[i][0]]=0;
            }
        }
        vector<int> ans1,ans2;
        for(auto it:mp){
            if(it.second==0){
                ans1.push_back(it.first);
            }
            else if(it.second==1){
                ans2.push_back(it.first);
            }
        }
        return {ans1,ans2};
    }
};