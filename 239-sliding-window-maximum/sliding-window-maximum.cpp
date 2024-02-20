class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> v;
        int l=0,r=0;

        while(r<nums.size()){
            while(!dq.empty() && nums[dq.back()]<nums[r]) dq.pop_back();
            dq.push_back(r);
            if(!dq.empty() && dq.front()<l) dq.pop_front();
            if(r-l+1==k){
                v.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return v;
    }
};