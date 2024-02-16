class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i:arr)mp[i]++;
        vector<int>v;
        for(auto i:mp) v.push_back(i.second);
        sort(v.begin(),v.end());
        int i;
        for(i=0;i<v.size();i++){
            if(k<v[i]) break;
            else k-=v[i];
        }
        return v.size()-i;
    }
};



