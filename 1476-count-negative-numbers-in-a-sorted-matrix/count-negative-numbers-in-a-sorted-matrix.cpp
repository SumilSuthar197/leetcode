class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r=grid[0].size()-1;
        int c=0,count=0;

        while(r>=0 && c<grid.size()){
            if(grid[c][r]<0){
                count+=grid.size()-c;
                r--;
            }
            else{
                c++;
            }
        }
        return count;
    }
};