class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                int maxFreq=0,minFreq=INT_MAX;
                for(auto i:mp){
                    minFreq=min(minFreq,i.second);
                    maxFreq=max(maxFreq,i.second);
                }
                sum+=(maxFreq-minFreq);
            }
        }
        return sum;
    }
};