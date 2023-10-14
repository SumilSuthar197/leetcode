class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> v;
        int prev=-1;
        
        for(int i=0;i<groups.size();i++){
            if(groups[i]!=prev){
                v.push_back(words[i]);
                prev=groups[i];
            }
        }
        
        return v;
    }
};