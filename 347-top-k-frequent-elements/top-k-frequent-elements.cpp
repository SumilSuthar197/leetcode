class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for( int i:nums) mp[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto i:mp){
            pq.push(make_pair(-i.second,i.first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};