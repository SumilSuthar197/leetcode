class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> mp;

        for(string& i:names){
            if(mp.find(i)!=mp.end()){
                string temp=i+'('+to_string(mp[i])+')';
                
                while(mp.count(temp)){
                    mp[i]++;
                    temp=i+'('+to_string(mp[i])+')';
                }
                mp[i]++;
                i=temp;
                mp[i]++;
                // i+='('+to_string(mp[i]-1)+')';
            }
            else{
                mp[i]++;
            }
        }
        return names;
    }
};