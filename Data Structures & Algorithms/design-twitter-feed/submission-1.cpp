class Twitter {
    unordered_map<int, unordered_set<int>> follower_following{};
    unordered_map<int, deque<pair<int, int>>> user_post{};
    int time {};
    constexpr static auto cmp = [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    };
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
       if(user_post[userId].size() >= 10) user_post[userId].pop_front();
       user_post[userId].push_back({tweetId, time}); 
       time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        follower_following[userId].insert(userId);
        vector<int> finalOut {};
        priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(cmp)> timeStamped_queue {cmp};
       auto& following = follower_following[userId]; 
       for(auto user: following){
            for(auto post: user_post[user])
                timeStamped_queue.push(post);
       }
        for(int i {}; !timeStamped_queue.empty() && i < 10; ++i){
            finalOut.push_back(timeStamped_queue.top().first);
            timeStamped_queue.pop();
        }
        return finalOut;
    }
    
    void follow(int followerId, int followeeId) {
        follower_following[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
       follower_following[followerId].erase(followeeId); 
    }
};
