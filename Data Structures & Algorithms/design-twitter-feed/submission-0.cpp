class Twitter {
private:
    int timestamp;

    unordered_map<int, vector<pair<int, int>>> tweets;

    unordered_map<int, unordered_set<int>> following;
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        for(auto& t : tweets[userId]) {
            pq.push(t);
        }

        for (int followeeId : following[userId]) {
            for (auto& t : tweets[followeeId]) {
                pq.push(t);
            }
        }

        vector<int> res;
        for(int i = 0; i < 10 && !pq.empty(); i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
