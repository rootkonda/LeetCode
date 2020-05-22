/*
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Target is N-1. So we check every possible combination by backtracking. Keep exploring each vertex and whenever the current vertex is target then add it to the anser.
*/


class Solution {
public:
    int target;
    vector<vector<int>> ans;
    void helper(vector<vector<int>>& graph,int curr,vector<int> temp)
    {
        if(target==curr)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<graph[curr].size();i++)
        {
            temp.push_back(graph[curr][i]);
            helper(graph,graph[curr][i],temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        target = (int)graph.size()-1;
        helper(graph,0,{0});
        return ans;
    }
};
