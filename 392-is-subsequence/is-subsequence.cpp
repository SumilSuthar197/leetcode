class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<t.size() && j<s.size()){
            if(s[j]==t[i]) {
                j++;
            }
            i++;
        }
        if(j==s.size()) return true;
        return false;
    }
};