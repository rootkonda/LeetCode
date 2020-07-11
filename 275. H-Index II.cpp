/*
https://leetcode.com/problems/h-index-ii/discuss/693427/C%2B%2B-or-BOTH-O(logn)-and-O(n)-solution-with-explanation

Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
*/


class Solution {
public:
    int hIndex(vector<int>& cit,int i=0) 
    {
        int ans = 0;
        int N=cit.size();
        int low=0;
        int high=N-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(cit[mid]>=N-mid)
            {
                ans = N-mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};
