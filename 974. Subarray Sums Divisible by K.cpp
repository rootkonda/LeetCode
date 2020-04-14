/**
https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/413234/DETAILED-WHITEBOARD!-BEATS-100-(Do-you-really-want-to-understand-It) 

For every element:
1. Calculate the prefix sum.
2. Take mod of current prefix sum and if it is <0 then add +K and mod %K again.
   1. +K works to get the +ve remainder value when mod value < 0
   2. %K of total value is because when there are +ve remainders, adding +K in earlier step will crosse the possible remainders of K so mod K the result.
 3. Keep track of the frequency of each remainder.
 4. Before updating the frequency, update the count if you find that remainder.
**/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K)
    {
        unordered_map<int,int> visited;
        int count = 0;
        int curr = 0;
        visited.insert({0,1});
        for(int i=0;i<A.size();i++)
        {
            curr +=A[i];
            int r = (curr%K;
            if(visited.find(r)!=visited.end())
                count+=visited[r];
            visited[r]++;
        }
        return count;
        
    }
};
