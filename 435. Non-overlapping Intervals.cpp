/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

1. First sort the intervals by the end time
2. Next, count the non-overlapping intervals
3. Finally subtract this count from total number of intervals.

*/

class Solution 
{
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& is) 
    {
        int cnt=1;
        if(is.size()==0)
            return {};
        sort(is.begin(),is.end(),cmp);
        int end = is[0][1];
        for(int j=1;j<is.size();j++)
        {
            if(is[j][0]>=end)
            {
                cnt++;
                end = is[j][1];
            }
        }
        return is.size()-cnt;
    }
};

/*
1,2
2,3
1,3
3,4

[[1,2]]
[[1,2],[2,3],[3,4],[1,3]]
[[1,2],[1,2],[1,2]]
[[1,2],[2,3]]
[[1,100],[11,22],[1,11],[2,12]]
*/
