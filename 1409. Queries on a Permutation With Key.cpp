/*
Given the array queries of positive integers between 1 and m, you have to process all queries[i] (from i=0 to i=queries.length-1) according to the following rules:

In the beginning, you have the permutation P=[1,2,3,...,m].
For the current i, find the position of queries[i] in the permutation P (indexing from 0) and then move this at the beginning of the permutation P. Notice that the position of queries[i] in P is the result for queries[i].
Return an array containing the result for the given queries.

Constraints:

1 <= m <= 10^3
1 <= queries.length <= m
1 <= queries[i] <= m

Instead of moving or shifting the elements in the array just update its positions in the array and treat the indexes of the permutation elements as the query values-1.

*/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) 
    {
        vector<int> ans;
        vector<int> per;
        for(int i=0;i<m;i++)
            per.push_back(i); // Maintain the positions of 1 to m elements
        for(int i=0;i<queries.size();i++)
        {
            int curr = per[queries[i]-1]; // Each query is nothing but the position of the permutations array. Just get the position value from it and return
            ans.push_back(curr);
            for(int j=0;j<m;j++)
            {
                if(per[j]<curr) // Update/incrment by 1 on all the positions which are lesser than current query value's position. Because as we are making the current value to move to front all elements before this will move backwards, which is nothing but incrementing the positions by 1
                    per[j]++;
            }
            per[queries[i]-1]=0; // Set the current query's position value to 0 it means we conceptually moved to beginning of the array but without moving it.
        }
        return ans;
    }
};
 
