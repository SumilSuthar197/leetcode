class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) {
        unordered_map<int, int> mp;
        for (int i : n1)
            mp[i]++;
        vector<int> ans;
        for (int i : n2) {
            if (mp[i] > 0) {
                ans.push_back(i);
                mp[i]--;
            }
        }
        return ans;
    }
};