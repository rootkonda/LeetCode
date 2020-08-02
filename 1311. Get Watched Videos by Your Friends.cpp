/*
There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

1. Use BFS to reach to the given level and maitain the queue with the id's at each level.
2. For each id, count the frequencies of friend.
3. Next use another map to sort by frequencies and maintain a set against each frequency.
4. Finally go thru the map and add the set to answer.
*/
class Solution 
{
public:
    unordered_map<string,int> mp;
    map<int,set<string>> rmp;
    vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& friends, int id, int level) 
    {
        vector<int> vis(100,0);
        queue<int> que;
        que.push(id);
        int curr=0;
        vis[id]=1;
        
        while(!que.empty() and curr!=level)
        {
            int n = que.size();
            while(n--)
            {
                int idx = que.front();
                que.pop();
               
                vector<int> vec = friends[idx];
     Foe           for(int i=0;i<vec.size();i++)
                {
                    if(vis[vec[i]]==0)
                    {
                        vis[vec[i]] = 1;
                        que.push(vec[i]);
                    }
                }
            }
            curr++;
        }
        while(!que.empty())
        {
            int idx = que.front();
            que.pop();
            for(auto vid : wv[idx])
                mp[vid]++;
        }
        vector<string> ans;
        for(auto itr : mp)
            rmp[itr.second].insert(itr.first);
        for(auto itr : rmp)
        {
            for(auto st : itr.second)
                ans.push_back(st);
        }
            
        return ans; 
    }
};
