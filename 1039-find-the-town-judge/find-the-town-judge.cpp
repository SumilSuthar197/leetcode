class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        unordered_map<int,int> mp;
        for(auto i:trust){
            mp[i[1]]++;
            mp[i[0]]--;
        }
        for(auto i:mp){
            if(i.second==n-1) return i.first;
        }
        return -1;
    }
};