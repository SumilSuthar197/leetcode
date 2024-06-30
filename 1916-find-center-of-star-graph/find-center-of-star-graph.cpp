class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> v(edges.size() + 1, 0);

        for (auto i : edges) {
            v[i[0] - 1] += 1;
            v[i[1] - 1] += 1;
            if (v[i[0] - 1] == edges.size())
                return i[0];
            if (v[i[1] - 1] == edges.size())
                return i[1];
        }
        return 0;
    }
};