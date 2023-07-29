class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0,j=flowerbed.size()-1;
        while(i<=j){
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==j || flowerbed[i+1]==0)){
                flowerbed[i]=1;
                n--;
            }
            i++;
            if(n<=0) return true;
        }
        return false;
    }
};