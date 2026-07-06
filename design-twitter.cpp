class Twitter {
public:
unordered_map<int, vector<int>> followmap;
    unordered_map<int, vector<pair<int,int>>> tweet;
    int time=0;
    Twitter() {
    
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq; //{time,tweetId}
        for(auto i:tweet[userId])
        {
            pq.push(i);
        }
        for(int followee:followmap[userId])
        {
            for(auto i:tweet[followee])
        {
            pq.push(i);
        }
        }
        vector<int>ans;
        while(!pq.empty() && ans.size()<10)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
         if(followeeId==followerId)
        return;
        auto &vec=followmap[followerId];
         if(find(vec.begin(), vec.end(), followeeId) == vec.end())
        {
            vec.push_back(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
       auto it = followmap.find(followerId);

        if(it != followmap.end())
        {
            auto& vec = it->second;
            vec.erase(remove(vec.begin(), vec.end(), followeeId), vec.end());
        }

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
