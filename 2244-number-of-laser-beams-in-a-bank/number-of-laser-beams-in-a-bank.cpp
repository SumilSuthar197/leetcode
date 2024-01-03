class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sd=0,ans=0;
        for(string c:bank){
            int temp=0;
            for(char i:c) temp+=int(i-'0');
            if(temp!=0){
                ans+=sd*temp;
                sd=temp;
            }
        }
        return ans;
    }
};