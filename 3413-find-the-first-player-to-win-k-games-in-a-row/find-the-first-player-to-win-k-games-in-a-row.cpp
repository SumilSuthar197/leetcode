class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int player = 0;
        int win = 0;
        for (int i = 1; i < skills.size(); i++) {
            if (skills[player] > skills[i])
                win++;
            else {
                player = i;
                win = 1;
            }
            if (win == k)
                break;
        }
        return player;
    }
};