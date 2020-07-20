/*
Given 2 integers n and start. Your task is return any permutation p of (0,1,2.....,2^n -1) such that :

p[0] = start
p[i] and p[i+1] differ by only one bit in their binary representation.
p[0] and p[2^n -1] must also differ by only one bit in their binary representation.
 
 
https://cp-algorithms.com/algebra/gray-code.html
Grey Code also makes sure that the last and first numbers also differ by only one bit.
We observe that :

0 ^ start = start (e.g., suppose start = 110, we have 0 ^ start = 110 )
If b1 and b2 differ by only one bit, start ^ b1 and start ^ b2 also differ by only one bit. (e.g., start = 110, b1 = 111, b2 = 101, we have start ^ b1 = 001, start ^ b2 = 011).
So start ^ i ^ i >> 1 makes sure that the permutation starts from start, while the permutation is still the valid gray code.
*/


class Solution {
public:
    vector<int> circularPermutation(int n, int start) 
    {
        vector<int> ans;
        for(int i=0;i<(1<<n);i++)
            ans.push_back(start^i^i>>1);
        return ans;
    }
};
