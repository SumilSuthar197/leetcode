class Solution {
public:
    string temp="";
    void checkMax(string s){
        if(temp.length()<s.length()){
            temp=s;
        }
    }
    void expandAroundIndex(string s,int i,int j){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            string temp=s.substr(i,j-i+1);
            checkMax(temp);
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        string t1,t2;
        for(int i=0;i<s.length();i++){
            expandAroundIndex(s,i,i);
            expandAroundIndex(s,i,i+1);
        }
        return temp;
    }
};