class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int> a,const vector<int> b){
        return a[1]<b[1];
    });
        int count=1;
        int temp = pairs[0][1];
        // for(auto i:pairs){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        for(int i=1;i<pairs.size();i++){
            if(temp<pairs[i][0]){
                count++;
                temp=pairs[i][1];
            }
        }
        return count;
    }
};