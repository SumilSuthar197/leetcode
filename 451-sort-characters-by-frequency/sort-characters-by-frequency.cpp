class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> v(256);
        for(auto i:s){
            v[i].first=i;
            v[i].second+=1;
        }
        sort(v.begin(),v.end(),[](pair<char,int> p1,pair<char,int> p2){
            return p1.second>p2.second;
        });
        // for(auto i:v){
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }
        s="";
        for(auto i:v){
            while(i.second--) s+=i.first;
        }
        return s;
    }
};