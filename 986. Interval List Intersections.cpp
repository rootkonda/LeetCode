/**
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)


1. start and end variables have the intersection points if exists.
Think of it like this.....say we have two intervals (0,2) and (1,5) and intersection is 1,2.
It starts with 0 and then 1,2,3,4,5. In order to find intersection we take maximum of starting points in both intervals and then minimum of end points if it exists. 

{ // outermost starting point
  { // intersection start point
  } // intersection end point
} // outermost end point

2. Question of moving which pointer forward is based on the intersection. Eliminate the lowest end point pointer because we are done with it and we have to look for intervals greater than that.


**/




class Solution {
 public:
     vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
     {
         vector<vector<int>> ans;
         if(A.size()==0)
             return {};
         if(B.size()==0)
             return {};
         int i=0;
         int j=0;
         
         while(i<A.size() and j<B.size())
         {
             int start = max(A[i][0],B[j][0]);
             int end = min(A[i][1],B[j][1]);
             
             if(start<=end)
                 ans.push_back({start,end});
             
             if(A[i][1]<B[j][1])
                 i++;
             else
                 j++;
         }
         return ans;
     }
};






