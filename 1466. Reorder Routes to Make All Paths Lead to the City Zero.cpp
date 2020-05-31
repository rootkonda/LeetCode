/*
There are n cities numbered from 0 to n-1 and n-1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [a, b] represents a road from city a to b.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach the city 0 after reorder.

 

We have keep adding all the outgoing edges ONLY starting from the nodes connected to 0. Whenever we add outgoing edges of a node, then we go to that node and remove its incoming edge. Similarly for all incoming edges remove the outgoing edge of that node. This is to avoid duplicate traversals.
*/


class Solution {
public:
    int ans = 0;
    unordered_map<int,unordered_set<int>> in,out;
    void helper(int node)
    {
        ans+=out[node].size();
        for(auto x : out[node])
        {
            in[x].erase(node); // edge reversed
            helper(x);
        }
        for(auto x : in[node])
        {
            out[x].erase(node); // To avoid duplicated calls
            helper(x);
        }
    }
    int minReorder(int n, vector<vector<int>>& con) 
    {
        for(auto vec : con)
        {
            out[vec[0]].insert(vec[1]);
            in[vec[1]].insert(vec[0]);
        }
        helper(0);
        return ans;
    }
};
