class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string t;
        for(auto i:s){
            if(c==0){
                c++;
                continue;
            }
            if(i=='(') c++;
            else c--;
            // cout<<i<<" "<<c<<"\n";
            if(c>0) t.push_back(i);
        }
        return t;
    }
};