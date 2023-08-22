class Solution {
public:
    string convertToTitle(int num) {
        string res="";
        while(num>0){
            num--;
            int m=num%26;
            res=(char)(65+m)+res;
            num-=m;
            num/=26;
        }
        return res;
    }
};
