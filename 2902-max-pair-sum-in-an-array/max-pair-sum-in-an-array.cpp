class Solution {
public:
    int max_digit(int n){
        int ans=-1;
        while(n>0){
            int temp=n%10;
            ans=max(ans,n%10);
            n=n/10;
        }
        return ans;
    }
    int maxSum(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(max_digit(nums[i])==max_digit(nums[j])){
                    ans=max(ans,nums[i]+nums[j]);
                }
            } 
        }
        return ans;
    }
};