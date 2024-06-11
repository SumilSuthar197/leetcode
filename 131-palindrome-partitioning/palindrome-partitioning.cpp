class Solution {
public:
    bool pali(string& s) {
        int n = s.size();

        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                return false;
            }
        }

        return true;
    }

    void solve(string& s, vector<vector<string>>& res, vector<string>& temp,
               int idx) {
        if (idx == s.size()) {
            res.push_back(temp);
        }

        for (int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i - idx + 1);
            if (pali(sub)) {
                temp.push_back(sub);
                solve(s, res, temp, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;

        solve(s, res, temp, 0);

        return res;
    }
};