class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            if(n%(i+1)==0){
                cout<<i<<" ";
                sum+=nums[i]*nums[i];
            }
        }
        return sum;
    }
};