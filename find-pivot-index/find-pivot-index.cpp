class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tsum=0;
        for(int i = 0; i < nums.size(); i++) {
            tsum += nums[i];
        }
        int lsum=0,rsum=0;
        for(int i = 0; i <nums.size(); i++){
            rsum=tsum-lsum-nums[i];
            if(lsum == rsum){
                return i;
            }
            lsum+=nums[i];
        }
        return -1;
    }
};