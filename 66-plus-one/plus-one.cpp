class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
        // vector<int> ans;
        // long int sum=0;
        // for(int i=0;i<digits.size();i++){
        //     sum=10*sum+digits[i];
        // }
        // sum=sum+1;
        // while(sum!=0){
        //     int temp=sum%10;
        //     ans.push_back(temp);
        //     sum=sum/10;
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
    }
};