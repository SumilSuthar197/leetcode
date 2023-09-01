class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
       unordered_map<char,int> mp;
       for(auto i:stones){
           mp[i]++;
       } 
       int c=0;
       for(auto i:jewels){
           if(mp.find(i)!=mp.end()) c+=mp[i];
       }
       return c;
    }
};