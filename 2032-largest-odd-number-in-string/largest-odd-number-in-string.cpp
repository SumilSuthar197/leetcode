class Solution {
public:
    string largestOddNumber(string num) {
        if((num.back()-'0')%2!=0) return num;
        int i;
        for(i=num.size()-2;i>=0;i--){
            if((num[i]-'0')%2!=0) break;
        }
        return num.substr(0,i+1);
    }
};