class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int,int> mp;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && nums2[i]>s.top()) s.pop();
            if(!s.empty()) mp[nums2[i]]=s.top();
            else mp[nums2[i]]=-1;
            s.push(nums2[i]);
        }
        for(int i:nums1){
            v.push_back(mp[i]);
        }

        return v;
    }
};