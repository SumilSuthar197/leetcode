class Solution {
public:
    int maxDepth(string s) {
        int l=0,r=0,sum=0;
        for(auto i:s){
            if(i=='(') l++;
            else if(i==')'){
                sum=max(sum,abs(l-r));
                r++;
            }
        }
        return sum;
        
    }
};