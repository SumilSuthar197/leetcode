class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        unordered_map<char,int> mp;
        for(;j<s.length();j++){
            mp[s[j]]++;
            for(;mp[s[j]]>1;i++){
                mp[s[i]]--;
            }
            ans=max(ans,j-i+1);
        }   
        return ans;    
    }
};