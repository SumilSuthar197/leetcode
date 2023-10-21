class Solution {
public:
    bool checkingValue(vector<vector<char>> v,char s){
        if(v[1][1]==s && v[2][2]==s && v[0][0]==s) return true;
        if(v[1][1]==s && v[0][2]==s && v[2][0]==s) return true;
        for(int i=0;i<3;i++){
            if(v[i][0]==s && v[i][1]==s && v[i][2]==s) return true;
            if(v[0][i]==s && v[1][i]==s && v[2][i]==s) return true;
        }
        return false;
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> v(3,vector<char>(3,'E'));
        for(int i=0;i<moves.size();i++){
            if(i%2==0) v[moves[i][0]][moves[i][1]]='X';
            else v[moves[i][0]][moves[i][1]]='0';
        }
        if(checkingValue(v,'X')) return "A";
        else if(checkingValue(v,'0')) return "B";
        else if(moves.size()==9) return "Draw";
        else return "Pending";
    }
};