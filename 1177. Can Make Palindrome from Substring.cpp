/*
Given a string s, we make queries on substrings of s.

For each query queries[i] = [left, right, k], we may rearrange the substring s[left], ..., s[right], and then choose up to k of them to replace with any lowercase English letter. 

If the substring is possible to be a palindrome string after the operations above, the result of the query is true. Otherwise, the result is false.

Return an array answer[], where answer[i] is the result of the i-th query queries[i].

Note that: Each letter is counted individually for replacement so if for example s[left..right] = "aaa", and k = 2, we can only replace two of the letters.  (Also, note that the initial string s is never modified by any query.)

Constraints:

1 <= s.length, queries.length <= 10^5
0 <= queries[i][0] <= queries[i][1] < s.length
0 <= queries[i][2] <= s.length
s only contains lowercase English letters.

Using prefix XOR/Sum array technique. But its tricky.

Goal is to find how many odd number of characters are there. i.e. Take the character count and check how many character counts are odd. However, in this XOR prefix array we will calculate a XOR value upto the character at every position.

In order to make it palindrome, we have to definetly make atleast n(size of string)/2 replacements of the odd character counts.
Think in terms of bits, we are setting bits in ch-'a' position's and also when we XOR again for the given range then we will be left out with set bits where there are odd character counts.
*/


class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) 
    {
        vector<bool> ans;
        vector<int> prefix(1); 
        int mask=0;
        for(auto ch : s)
            prefix.push_back(mask^=1<<(ch-'a')); //
        
        for(auto &q :queries)
            ans.push_back(q[2]>=__builtin_popcount(prefix[q[1]+1]^prefix[q[0]])/2);
        // prefix[q[1]+1]^prefix[q[0]] - Gives the odd count of characters, which is the number of set bits.
        // Think about the set bits in bit representation.
        return ans;
    }
};
