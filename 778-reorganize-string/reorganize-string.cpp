class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        int maxFreq=INT_MIN;
        char maxChar=0;
        for(char i:s){
            mp[i]++;
            if(mp[i]>maxFreq){
                maxFreq=mp[i];
                maxChar=i;
            }
        }
        int i=0;
        while(i<s.size() && maxFreq>0){
            s[i]=maxChar;
            maxFreq--;
            mp[maxChar]--;
            i+=2;
        }
        if(maxFreq!=0) return "";

        for(auto m:mp){
            while(m.second>0){
                i= i>=s.length()?1:i;
                s[i]=m.first;
                i+=2;
                m.second--;
            }
        }

        return s;
    }
};