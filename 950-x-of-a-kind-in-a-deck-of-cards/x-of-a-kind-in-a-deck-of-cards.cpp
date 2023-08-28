class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()<2) return false;
        unordered_map<int,int> mp;
        for(auto i:deck){
            mp[i]++;
        }
        int minFreq=mp[deck[0]];
        for(auto i:mp){
            minFreq=__gcd(minFreq,i.second);
        }
        return minFreq>1;
    }
};