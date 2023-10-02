class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        int i;
        for(i=nums.size()-1;i>=0;i--){
            if(nums[i]<=k) s.insert(nums[i]);
            if(s.size()==k) break;
        }
        return nums.size()-i;
        
    }
};