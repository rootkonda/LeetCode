/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.


Maintain HashMap for user -> followers
Maintain HashMap for user -> tweets
For every tweet, assign a new id to it.
Only consider the current user and his followers only.

*/

class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int,unordered_set<int>> graph;
    map<int,vector<pair<int,int>>> tweets;
    int id=0;
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        tweets[userId].push_back({id++,tweetId});    
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        set<pair<int,int>,greater<pair<int,int>>> ans;
        for(auto pr : tweets[userId])
            ans.insert(pr);
        for(auto it : graph[userId])
        {
            for(auto pr : tweets[it])
                ans.insert(pr);
        }
        vector<int> res;
        for(auto it : ans)
        {
            res.push_back(it.second);
            if(res.size()==10)
                break;
        }  
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        graph[followerId].insert(followeeId);    
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        graph[followerId].erase(followeeId);     
    }
};
/*
["Twitter","postTweet","postTweet","getNewsFeed"]
[[],[1,5],[1,3],[1]]
["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]
["Twitter","postTweet","follow","getNewsFeed"]
[[],[1,5],[1,1],[1]]
["Twitter","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","follow","follow","follow","follow","follow","follow","follow","follow","follow","follow","follow","follow","getNewsFeed","getNewsFeed","getNewsFeed","getNewsFeed","getNewsFeed"]
[[],[1,6765],[5,671],[3,2868],[4,8148],[4,386],[3,6673],[3,7946],[3,1445],[4,4822],[1,3781],[4,9038],[1,9643],[3,5917],[2,8847],[1,3],[1,4],[4,2],[4,1],[3,2],[3,5],[3,1],[2,3],[2,1],[2,5],[5,1],[5,2],[1],[2],[3],[4],[5]]
*/
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
