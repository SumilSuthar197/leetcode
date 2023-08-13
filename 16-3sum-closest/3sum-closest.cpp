class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum=INT_MAX;
        if(target<0) sum=-sum;
        sort(nums.begin(),nums.end());
        for(int m=0;m<nums.size()-1;m++){
            int i=m+1,j=nums.size()-1;
            while(i<j){
                int total=nums[m]+nums[i]+nums[j];
                if(total<target) i++;
                else j--;
                if(abs(target-sum)>abs(target-total)) sum=total;
            }
        }
        return sum;
    }
};