/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

Standard Topological Sorting + Cycle detection.

a. Perform DFS for each vertex and keep adding the vertex to the answer when we have either explored all dependent nodes or there is no vertices to explore.
b. To make sure that we do not explore same vertex or if we have a cycle: I use the visited map.
c. Visited has 3 types of values

0 - Not yet visited the vertex
1 - Exploration is in progress
2 - Exploration is complete
Initially all the vertices are not explored so assign them as zero.
d. Every time we start exploring a vertex, assign that vertex to 1 ( means its in progress )
e. After we complete exploring a vertex, assign that vertex to 2 ( means exploration completed succesfully)
f. If the given input has a cycle then at some point we will encounter the visited value as 1 for that vertex so return empty vector.

Cycle Detection Technique
--------------------------
Use the following approach: consider we have three colors, and each vertex should be painted with one of these colors. "White color" means that the vertex hasn't been visited yet. "Gray" means that we've visited the vertex but haven't visited all vertices in its subtree. "Black" means we've visited all vertices in subtree and left the vertex. So, initially all vertices are white. When we visit the vertex, we should paint it gray. When we leave the vertex (that is we are at the end of the dfs() function, after going throung all edges from the vertex), we should paint it black. If you use that approach, you just need to change dfs() a little bit. Assume we are going to walk through the edge v->u. If u is white, go there. If u is black, don't do anything. If u is gray, you've found the cycle because you haven't left u yet (it's gray, not black), but you come there one more time after walking throung some path.

To keep vertices' colors replace boolean array with char or integer array and just use values in range [0..2].

https://www.youtube.com/watch?v=ddTC4Zovtbc

*/


class Solution {
public:
    vector<int> ans;
    bool cycle=false;
    // 0 - not visited, 2 - visited, 1 - in progress
    void dfs(vector<vector<int>>& graph,unordered_map<int,int>& visited,int node)
    {
        if(visited[node]==2)
            return;
        visited[node] = 1;
        for(int i=0;i<graph[node].size();i++)
        {
            if(visited[graph[node][i]]==0)
                dfs(graph,visited,graph[node][i]);
            else if(visited[graph[node][i]]==1)
            {
                cycle=true;
                return;
            }
        }
        visited[node] = 2;
        ans.push_back(node);
    }
    vector<int> findOrder(int n, vector<vector<int>>& preq)
    {
        vector<vector<int>> graph(n,vector<int>());
        unordered_map<int,int> visited;
        for(auto pr : preq)
            graph[pr[0]].push_back(pr[1]);
        
        for(int i=0;i<n;i++)
            visited[i]=0;
            
        for(int i=0;i<n;i++)
            dfs(graph,visited,i);
        return (cycle ? vector<int>{} : ans);
    }
};

/*
2
[[1,0]]
4
[[1,0],[2,0],[3,1],[3,2]]
2
[[0,1],[1,0]]
4
[[0,1],[3,1],[1,3],[3,2]]
2
[[0,1]]

*/
