class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums) mp[i]++;
        int n=0;
        for(auto i:mp){
            // cout<<i.first<<" "<<i.second<<"\n";
            if(i.second%3==0) n+=i.second/3;
            else if(i.second%3==1){
                i.second-=4;
                if(i.second<0) return -1;
                n+=i.second/3;
                n+=2;
            }
            else if(i.second%3==2){
                n+=(i.second-2)/3;
                n+=1;
            } 
        }
        return n;
    }
};