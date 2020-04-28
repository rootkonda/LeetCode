/*
    https://leetcode.com/problems/longest-arithmetic-sequence/
    
    It is very similar to LIS problem, but the catch is here we have more constraints 
    than LIS, we can just add a term to be part of a series like LIS, here it can
    only be part of a series when it also shares the common diff that is there in the series.
    
    Now we just track the max length series diff for each term, then also it wont work, since
    there might be a term later on which completes a longer series if it gets a few more sequences.
    
    EG: 1,2,4,6,8
    for 4, if we save only diff 3 {1,4}, then it wont make the longest length with {2,4,6,8} with 
    diff 2, so we save the max length ending at each term for all the differences encountered.
    with the previous terms.
    
    We save info like: for 4: (3,2){with 1}, (2,2){with2}
    So for 6, we can just see if there was a series with diff=2 ending at 4, that gives
    us dp[indexof(4)][2] = 2, so dp[indexof(6)] = 2 + 1
    
    TC: O(N^2)
    SC: O(N*diff), diff: max unique number of differences between any two terms of array, which can be N-1
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& A)
    {
        vector<unordered_map<int,int>>  ap(A.size());
        int i = 1;
        int ans = 0;
        while(i<A.size())
        {
            int j = 0;
            while(j < i)
            {
                int diff = A[i]-A[j];
                int ap_len = 1+(ap[j][diff] ? ap[j][diff] : 0); // len of an ap for a given difference at jth position with the same difference earlier.
                int ap_end_len = ap[i][diff] ? ap[i][diff] : 2; // For the first time, the difference at ith position will have value 2 because two elements are required to form a sequence or find difference.
                ap[i][diff] = max(ap_len,ap_end_len); // Update the longest arthimetic sequence at ith position for the given difference.
                ans = max(ans,ap[i][diff]); keep track of the maximum difference at a given ith position.
                j++;
            }
            i++;
        }
        return ans;
    }
};
