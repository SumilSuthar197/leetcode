class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,mid;
        int ans=INT_MAX;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]<nums[e]){
                ans=min(ans,nums[mid]);
                e=mid-1;
            }
            else{
                ans=min(ans,nums[s]);
                s=mid+1;
            }
        }
        return ans;
    }
};