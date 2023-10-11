class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        for(int i:bills){
            if(i==20){
                if(mp[10]>=1 && mp[5]>=1){
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>=3) mp[5]-=3;
                else return false;
            }
            else if(i==10){
                if(mp[5]>0) mp[5]--;
                else return false;
            }
            mp[i]++;
        }
        return true;
    }
};