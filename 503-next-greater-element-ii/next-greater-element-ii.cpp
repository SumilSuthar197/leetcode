class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<int> v(nums.size(),-1);
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--){
            while(!s.empty() && nums[i]>=s.top()) s.pop();
            if(!s.empty()) v[i]=s.top();
            s.push(nums[i]);
        }
        return vector<int>(v.begin(),v.begin()+n);
    }
};