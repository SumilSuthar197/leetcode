class Solution {
public:
    int count(int red, int blue, bool flag) {
        int i = 1;
        while (red >= 0 && blue >= 0) {
            if (i % 2 == 0) {
                flag ? red -= i : blue -= i;
            } else {
                flag ? blue -= i : red -= i;
            }
            // cout << red << " " << blue << " " << i << "\n";
            if (red < 0 || blue < 0) {
                i--;
                break;
            }
            i++;
        }
        return i;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(count(red, blue, true), count(red, blue, false));
    }
};