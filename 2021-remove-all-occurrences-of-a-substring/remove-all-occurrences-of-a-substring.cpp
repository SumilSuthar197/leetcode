class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=part.length();
        while(1){
            if(s.find(part)!=string::npos){
                s.replace(s.find(part),n,"");
            }
            else break;
        }
        return s;
    }
};