class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0;i<num.length();i++){
            while(!s.empty() && k>0 && s.top()>num[i]){
                s.pop();
                k--;
            }
            if(!s.empty() || num[i]!='0')s.push(num[i]);
        }
        while(!s.empty() && k>0){
            s.pop();
            k--;
        }
        string ans="";
        while(!s.empty()) ans += s.top(), s.pop();
        reverse(ans.begin(), ans.end());
        return ans.empty()?"0":ans;
    }
};