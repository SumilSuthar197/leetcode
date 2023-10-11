class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0;
        for(int i:bills){
            if(i==20){
                if(t>0 && f>0){
                    f--;t--;
                }
                else if(f>=3) f-=3;
                else return false;
            }
            else if(i==10){
                t++;
                if(f>0) f--;
                else return false;
            }
            else{
                f++;
            }
        }
        return true;
    }
};