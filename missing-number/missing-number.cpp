class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int count=nums.size();
        int sum=0;
        int missingNumber=(count*(count+1))/2;
        for(int i=0;i<count;i++){
            sum+=nums[i];
        }
        return missingNumber-sum;
    }
};