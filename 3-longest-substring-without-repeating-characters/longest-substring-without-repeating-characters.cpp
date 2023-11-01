class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0,r=0,maxLen=0;
        for(;r<s.size();r++){
            mp[s[r]]++;
            for(;mp[s[r]]>1;l++){
                mp[s[l]]--;
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};