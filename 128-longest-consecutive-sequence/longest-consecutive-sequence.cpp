class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count=1,maxCount=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
            if(nums[i]-nums[i-1]==1) count++;
            else{
                maxCount=max(maxCount,count);
                count=1;
            }
            }
        }
        return max(maxCount,count);
    }
};