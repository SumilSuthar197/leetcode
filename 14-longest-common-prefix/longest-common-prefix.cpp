class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        string res;
        while(1){
            char c=0;
            for(auto s:strs){
                if(i>=s.size()){
                    c=0;
                    break;
                }
                if(c==0) c=s[i];
                else if(s[i]!=c){
                    c=0;
                    break;
                }    
            }
            if(c==0) break;
            res.push_back(c);
            i++;
        }
        return res;
        
    }
};