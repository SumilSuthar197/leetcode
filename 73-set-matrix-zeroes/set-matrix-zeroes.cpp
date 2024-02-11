class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> col;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i:rows) matrix[i].assign(m, 0);
        for(int j:col){
            for(int i=0;i<n;i++) matrix[i][j]=0;
        }
    }
};