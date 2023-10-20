class Solution {
public:
string fn(string s){
    string res;
    for(char i:s){
        if(i=='#'){
            if(!res.empty()) res.pop_back();
        }
        else res.push_back(i);
    }
    // cout<<res<<"\n";
    return res;
}
    bool backspaceCompare(string s, string t) {
        return fn(s)==fn(t);
    }
};