class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, ans = 0, n = s.size();
        vector<int> v(3, -1);
        for (; r < n; r++) {
            v[s[r] - 'a'] = r;
            if (v[0] != -1 && v[1] != -1 && v[2] != -1) {
                ans += *min_element(v.begin(), v.end())+1;
            }
        }
        return ans;
    }
};