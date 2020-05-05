/*
Given a collection of intervals, merge all overlapping intervals.

1. Intervals means mostly sort first. Next to find the overlaps, we have to check the start of next interval is <=end of previous interval then it means there is a overlap so take the max end value from previous and current intervals.
2. If there is no overlap then update the start and end and add it to the answer. 
3. At the end add the start and end again to the answer because we are starting the loop from 1.
O(nlogn) + o(n)
*/



class Solution {
 public:
     vector<vector<int>> merge(vector<vector<int>>& intervals)
     {
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
         vector<vector<int>> ans;
         if(intervals.size()==0)
             return {};
         sort(intervals.begin(),intervals.end());
         int start = intervals[0][0];
         int end = intervals[0][1];
         for(int i=1;i<intervals.size();i++)
         {
             if(intervals[i][0]<=end)
                end = max(end,intervals[i][1]);
             else
             {
                 ans.push_back({start,end});
                 start = intervals[i][0];
                 end = intervals[i][1];
             }
         }
         ans.push_back({start,end});
         return ans; 
     }
 };
