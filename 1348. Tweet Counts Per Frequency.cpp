/*
Implement the class TweetCounts that supports two methods:

1. recordTweet(string tweetName, int time)

Stores the tweetName at the recorded time (in seconds).
2. getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)

Returns the total number of occurrences for the given tweetName per minute, hour, or day (depending on freq) starting from the startTime (in seconds) and ending at the endTime (in seconds).
freq is always minute, hour or day, representing the time interval to get the total number of occurrences for the given tweetName.
The first time interval always starts from the startTime, so the time intervals are [startTime, startTime + delta*1>,  [startTime + delta*1, startTime + delta*2>, [startTime + delta*2, startTime + delta*3>, ... , [startTime + delta*i, min(startTime + delta*(i+1), endTime + 1)> for some non-negative number i and delta (which depends on freq).


*/
class TweetCounts {
public:
    unordered_map<string,vector<int>> tcount;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) 
    {
       tcount[tweetName].push_back(time); 
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) 
    {
        int delta;
        if(freq=="minute")
            delta = 60;
        else if(freq=="hour")
            delta = 3600;
        else
            delta = 86400;
        
        int interval_start = startTime;
        int interval_end = min(endTime+1,startTime+delta);
        
        vector<int> ans;
        int i=1;
        while(interval_start<=endTime)
        {
            int count=0;
            for(auto time : tcount[tweetName])
            {
                if(time<interval_end and time>=interval_start)
                     count++;
            }
            ans.push_back(count);
            interval_start = startTime+delta*i;
            interval_end = min(endTime+1,startTime+delta*(i+1));
            i++;
        }
        return ans;
    }
};


//Using lower_bound and upper_bound to search inside a set.

class TweetCounts {
public:
    unordered_map<string, set<int>> tweets;
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) { // in seconds
        tweets[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> ans;
        int n(freq[0] == 'm' ? 60 : freq[0] == 'h' ? 3600 : 86400);
        for (int i = startTime; i <= endTime; i += n)
            ans.push_back(distance(tweets[tweetName].lower_bound(i), tweets[tweetName].upper_bound(min(i + n - 1, endTime))));
        return ans;
    }
};
