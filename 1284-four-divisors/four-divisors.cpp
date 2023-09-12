class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            int total=0,c=0;
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    if(i/j==j){
                        total+=j;
                        c++;
                    }
                    else{
                        total+=j+(i/j);
                        c+=2;
                    }
                }
            }
            if(c==4) sum+=total;
        }
        return sum;
    }
};