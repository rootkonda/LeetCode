/*
Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
F.length >= 3;
and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

*/


class Solution {
public:
    bool backtrack(string s, int start, vector<int>& nums)
    {
        if(start>=s.size() and nums.size()>=3)
            return true;
        int ssz = s[start]=='0' ? 1 : 10;
        for(int i=1;i<=ssz and start+i<=s.size();i++)
        {
            long val = stol(s.substr(start,i));
            if(val>=INT_MAX)
                return false;
            int sz=nums.size();
            if(sz>=2 and (long long)nums[sz-1]+nums[sz-2]<val)
                return false;
            if(sz<=1 or (long long)nums[sz-1]+nums[sz-2]==val)
            {
                nums.push_back(val);
                if(backtrack(s,start+i,nums))
                    return true;
                nums.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string S) 
    {
        vector<int> nums;
        backtrack(S,0,nums);
        return nums;
    }
};
