class Solution {
public:
    void intersection(unordered_map<char, int>& a,
                      unordered_map<char, int>& b) {
        for (auto i : a) {
            a[i.first] = min(i.second, b[i.first] ? b[i.first] : 0);
        }
    }
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> prev, curr;
        // counting freq in words[0]
        for (char i : words[0]) {
            prev[i]++;
        }

        // compare 1 to words.size() & find min
        for (int i = 1; i < words.size(); i++) {
            // cout << words[i] << "\n";
            for (char i : words[i]) {
                if (prev.find(i) != prev.end()) {
                    curr[i]++;
                    // cout << i << curr[i] << "\n";
                }
            }
            intersection(prev, curr);
            curr.clear();
        }
        vector<string> ans;
        for (auto i : prev) {
            while (i.second--)
                ans.push_back(string(1, i.first));
        }
        return ans;
    }
};