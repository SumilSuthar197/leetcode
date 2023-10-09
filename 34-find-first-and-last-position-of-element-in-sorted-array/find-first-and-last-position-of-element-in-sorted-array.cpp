class Solution {
public:
    int startIndex(vector<int>& nums,int target){
        int l=0,h=nums.size()-1;
        if(nums[0]==target) return 0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]==target && nums[m-1]!=target) return m;
            else if(nums[m]<target) l=m+1;
            else h=m-1;
        }
        return -1;
    }

    int lastIndex(vector<int>& nums,int target){
        int l=0,h=nums.size()-1;
        if(nums[h]==target) return h;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]==target && nums[m+1]!=target) return m;
            else if(nums[m]>target) h=m-1;
            else l=m+1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        
        return {startIndex(nums,target),lastIndex(nums,target)};
    }
};