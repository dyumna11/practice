class Twitter {
public:
unordered_map<int, unordered_set<int>> followmap;
    unordered_map<int, vector<pair<int,int>>> tweet;
    int time=0;
    Twitter() {
    
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //{time,tweetId}
        for(auto i:tweet[userId])
        {
            pq.push(i);
            if(pq.size()>10)
            pq.pop();
        }
        for(auto followee:followmap[userId])
        {
            for(auto i:tweet[followee])
        {
            pq.push(i);
             if(pq.size()>10)
            pq.pop();
        }
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);

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
