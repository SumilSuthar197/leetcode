class Solution {
public:
    void dfs(int start, vector<int>& vis, vector<int> adj[]) {
        vis[start] = 1;

        for (int i : adj[start]) {
            if (vis[i] == 1)
                continue;
            dfs(i, vis, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        vector<int> v[n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, v);
                ans++;
            }
        }
        return ans;
    }
};