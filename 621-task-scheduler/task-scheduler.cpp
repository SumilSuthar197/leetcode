class Solution {
public:
    typedef pair<int, int> pi;
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> mp;
        for (char i : tasks)
            mp[i - 'A']++;
        priority_queue<int> pq;
        queue<pi> q;
        int cnt = 0;
        for (auto i : mp) {
            pq.push(i.second);
        }
        while (!pq.empty() || !q.empty()) {
            if (!q.empty() && q.front().first + n < cnt) {
                pq.push(q.front().second);
                q.pop();
            }
            if (!pq.empty()) {
                int temp = pq.top();
                pq.pop();
                if (temp - 1 > 0) {
                    q.push(make_pair(cnt, temp - 1));
                }
            }
            cnt++;
        }
        return cnt;
    }
};