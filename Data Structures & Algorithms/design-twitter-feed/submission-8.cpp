class Twitter {
        unordered_map<int, vector<int>> follower_map {};
        unordered_map<int, std::deque<pair<int, int>>> tweet_map {};
        int count {};
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
       if(tweet_map[userId].size() >= 10) tweet_map[userId].pop_front();
       tweet_map[userId].emplace_back(make_pair(tweetId, count));
       count++; 
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<int> res {};
        if(std::ranges::find(follower_map[userId], userId) == follower_map[userId].end())
            follower_map[userId].push_back(userId);

       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap {};
       priority_queue<vector<int>> maxHeap {};
       for(auto followee: follower_map[userId]){
            if(tweet_map[followee].empty()) continue;
            int indx = tweet_map[followee].size() - 1;
            auto latest_tweet = tweet_map[followee][indx];
            minHeap.emplace(std::vector{latest_tweet.second, latest_tweet.first, followee, indx});
            if(minHeap.size() > 10) minHeap.pop();
       } 
       while(!minHeap.empty()){
        maxHeap.push(minHeap.top());
        minHeap.pop();
       }
       while(!maxHeap.empty() && res.size() < 10){
        auto tweet_info = maxHeap.top();
        res.push_back(tweet_info[1]);
        maxHeap.pop();
        int indx = tweet_info[3];
        if(indx > 0){
            auto tweet = tweet_map[tweet_info[2]][indx - 1];
            maxHeap.emplace(std::vector{tweet.second, tweet.first, tweet_info[2], indx - 1});
        }
       }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        auto &vec = follower_map[followerId];
        if(std::ranges::find(vec, followeeId) == vec.end())
            follower_map[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        std::vector<int>::iterator to_delete;
        auto &vec = follower_map[followerId];
        to_delete = std::ranges::find(vec, followeeId);
        if(to_delete != vec.end())
            vec.erase(to_delete);
    }
 
};
