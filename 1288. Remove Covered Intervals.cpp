/*

Given a list of intervals, remove all intervals that are covered by another interval in the list. Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals.


Sort the intervals based on right interval and start the comparison from last 2 intervals.
Whenever an interval is covering another interval then maintain a pointer to the interval covering it and use this interval for next comparison. Whenever the interval is not covered then simply update the pointer to current interval.
*/

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return (a[1]<b[1]);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals,int cnt=0,int idx=0) 
    {
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=intervals.size()-2,idx=intervals.size()-1;i>=0;i--)
        {
            if(intervals[idx][0]>=intervals[i][0] and intervals[idx][1]<=intervals[i][1])
                cnt++,idx=i;
            else if(intervals[i][0]>=intervals[idx][0] and intervals[idx][1]>=intervals[i][1])
                cnt++;
            else
                idx = i;
        }
        return intervals.size()-cnt;
    }
};
