class Twitter {
public:
    priority_queue<vector<int>> pq;
    unordered_map<int, set<int>> mp;
    int time = 0;
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        pq.push({time++, userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int n = 0;
        priority_queue<vector<int>> temp = pq;
        while (!temp.empty() && n < 10) {
            auto topEle = temp.top();
            temp.pop();
            if (topEle[1] == userId ||
                mp[userId].find(topEle[1]) != mp[userId].end()) {
                n++;
                ans.push_back(topEle[2]);
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */