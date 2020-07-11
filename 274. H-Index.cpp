/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

First element greater than or equal to the remaining elements including the current index element.

*/

class Solution {
public:
    int hIndex(vector<int>& cit,int i=0) 
    {
        int ans = 0;
        int N=cit.size();
        sort(begin(cit),end(cit));
        for(i=0;i<N and cit[i]<N-i;i++);
        return N-i;
    }
};
