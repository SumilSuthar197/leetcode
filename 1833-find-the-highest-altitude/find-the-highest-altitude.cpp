class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int result=INT_MIN;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            result=max(sum,result);
        }
        return result>0?result:0;
    }
};