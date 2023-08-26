class Solution {
public:
    int myAtoi(string s) {
        int res=0,sign=1,i=0;
        while(s[i]==' ') i++;

        if(i<s.size() && (s[i]=='+' || s[i]=='-')){
            sign= s[i]=='+'?1:-1;
            i++;
        }

        while(i<s.size() && isdigit(s[i])){
            if(res>INT_MAX/10 || (res==INT_MAX/10 && s[i] >'7')){
                return sign==-1?INT_MIN  : INT_MAX;
            }
            res=res*10+(s[i]-'0');
            i++;
        }
        return res*sign;
    }
};