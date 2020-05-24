/*
On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

Explanation:
------------
Using union find algorithm find the connected vertices satisfying the condition of sharing row or column with each other.
Answer will be number of vertices, which are shared with each other is the maximum number we can remove.

*/


class Solution {
public:
    int n;
    vector<int> parent;
    int find(int x)
    {
        return parent[x] == x ? x : find(parent[x]);
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        n = (int)stones.size();
        parent.resize(n,0);
        for(int i=0;i<n;i++)
            parent[i] = i;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
                {
                    int a = find(i);
                    int b = find(j);
                    if(a!=b)
                        parent[b] = a;
                }
            }
        }
        int no_parent=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                no_parent++;
        }
        return n-no_parent;
    }
};
