/*

There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Constraints:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.


BFS
---
1. We have to take k steps from sources and make a note of all adjacent nodes to the current node.
2. After noting down, increment the steps counter to say that we have take 1 step and make sure that is within the limit of k steps.
3. Next iteration, for each node make a note of all its adjacent nodes only when the cost of reaching that node is smaller than the already calculated cost(ans). This will prevent the cycle or overflow issue. So no need to use visited

*/
class Solution {
public:
    int ans = INT_MAX;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        unordered_set<int> visited;
        int steps=0;
        for(auto fl : flights)
            graph[fl[0]].push_back({fl[1],fl[2]});
        
        queue<pair<int,int>> nodes;
        nodes.push({src,0});
        while(!nodes.empty())
        {
            int n=nodes.size();
            while(n--)
            {
                pair<int,int> curr = nodes.front();
                nodes.pop();
                if(curr.first==dst)
                    ans = min(ans,curr.second);
                for(auto vtx : graph[curr.first])
                    if(vtx.second+curr.second<ans)
                        nodes.push({vtx.first,vtx.second+curr.second});
            }
            if(steps>k)
                break;
            steps++;
        }
        return (ans!=INT_MAX ? ans : -1);
    }
};

/*
DFS
---
1. From source, recursively explore all adjacent nodes for each node.
2. In this approach,we have to use visited to save some time
3. Two conditions are important here:
  a. Every time we have to check if current cost+new cost is less than answer(already calculated cost) if so then do recursion or else do not.
  b. Everytime check that we are not exceeding the k stops at any call.
*/

class Solution {
public:
    
    int ans = INT_MAX;
    void dfs(vector<vector<pair<int,int>>>& graph, int src, int dst, int K,int cost,unordered_set<int> visited)
    {
        if(src==dst)
        {
            if(K+1>=0)
                ans = min(ans,cost);
            return;
        }
        if(visited.count(src)>0 or K+1<0)
            return;
        visited.insert(src);
        for(auto ed : graph[src])
        {
            if(cost+ed.second>ans)
                continue;
            dfs(graph,ed.first,dst,K-1,cost+ed.second,visited);
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        unordered_set<int> visited;
        for(auto fl : flights)
        {
            graph[fl[0]].push_back({fl[1],fl[2]});
        }
        dfs(graph,src,dst,K,0,visited);
        return (ans!=INT_MAX ? ans : -1);
    }
};

/*

10
[[3,4,4],[2,5,6],[4,7,10],[9,6,5],[7,4,4],[6,2,10],[6,8,6],[7,9,4],[1,5,4],[1,0,4],[9,7,3],[7,0,5],[6,5,8],[1,7,6],[4,0,9],[5,9,1],[8,7,3],[1,2,6],[4,1,5],[5,2,4],[1,9,1],[7,8,10],[0,4,2],[7,2,8]]
6
0
7
5
[[1,2,10],[2,0,7],[1,3,8],[4,0,10],[3,4,2],[4,2,10],[0,3,3],[3,1,6],[2,4,5]]
0
4
1
5
[[4,1,1],[1,2,3],[0,3,2],[0,4,10],[3,1,1],[1,4,3]]
2
1
1
*/
