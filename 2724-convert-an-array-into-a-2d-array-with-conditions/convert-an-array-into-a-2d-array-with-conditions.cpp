class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(nums.size()+1);
        vector<vector<int>> ans;
        for(int i:nums){
            if(freq[i]>=ans.size()) ans.push_back({});
            ans[freq[i]].push_back(i);
            freq[i]++;
        }
        return ans;

    // O(n^2):
    //    unordered_map<int,int> mp;
    //    int maxLength=0;
    //    for(int i:nums){
    //        mp[i]++;
    //        maxLength=max(maxLength,mp[i]);
    //    }
    //    vector<vector<int>> ans(maxLength, vector<int>{});
    //    for(auto i:mp){
    //        int j=0;
    //        while(i.second>0){
    //            ans[j].push_back(i.first);
    //            j++;
    //            i.second--;
    //        }
    //    }
    //    return ans;
    }
};