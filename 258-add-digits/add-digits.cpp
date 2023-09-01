class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            num=num%10 +num/10;
            // cout<<num<<"\n";
        }
        return num;
    }
};