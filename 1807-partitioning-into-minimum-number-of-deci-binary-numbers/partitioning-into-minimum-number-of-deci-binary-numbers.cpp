class Solution {
public:
    int minPartitions(string n) {
        int maxEle=0;
        for(auto i:n){
            if(maxEle<i) maxEle=i;
            if(maxEle=='9') return 9;
        }
        return (maxEle-'0');
    }
};