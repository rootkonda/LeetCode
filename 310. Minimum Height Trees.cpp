/*


Idea is to find the center of the given graph from which the height to the leaf is minimum. The center node can be one or two. In other words, if the longest path in the given graph has even number of nodes, then we will have two centers as our answer and for odd number of nodes, we will have only 1 center as our answer.

Example 1 in description, the longest path is 0->1->2 or 0->1->3 (total 3 nodes) so 1 is our answer.
Example 2 in description, the longest path is 1 or 2 or 0->3->4->5 (total 4 nodes) so answer is 3,4.

A node which has only one node connected to it in its adjacency list is called as leaf node.

Removing the leaf node means we have to remove this leaf from the adjacency list of the leaf's adjacent node.
The adjacent node may still have two or more nodes connected to it or it would have become leaf node as we removed a leaf before. At any point, after removing the leaf if the adjacent node becomes leaf then add it to a new leaf list for next iteration of removal.

The exit condtion is n>2 because the number of nodes left after removing leaf nodes will either be two or one, which is our answer.


https://www.youtube.com/watch?v=Bl9l5cUgTnQ
*/



class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<int> leaves;
        vector<vector<int>> graph(n,vector<int>());
        
        for(auto ed : edges)
        {
            graph[ed[0]].push_back(ed[1]);
            graph[ed[1]].push_back(ed[0]);
        }
        //Prepare the list of leaves to remove
        for(int i=0;i<n;i++)
        {
            if(graph[i].size()==1)
                leaves.push_back(i);
        }
        while(n>2)
        {
            n-=leaves.size();
            vector<int> new_leaves;
            for(auto leaf : leaves)
            {
                int adj = graph[leaf][0];
                vector<int>::iterator itr = remove(graph[adj].begin(),graph[adj].end(),leaf);
                graph[adj].erase(itr,graph[adj].end());
                if(graph[adj].size()==1)
                    new_leaves.push_back(adj);
            }
            leaves = new_leaves;
        }
        if(leaves.size()==0)
            return {0};
        return leaves;
    }
};
