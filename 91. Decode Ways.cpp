/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.



Key is to store the number of ways possible at each character. Always keep track of current character and previous character.
If both are not null and valid characters then we should just take the sum of previous two sizes of string.

https://leetcode.com/problems/decode-ways/discuss/30522/Java-2ms-DP-solution-with-detailed-explanation-and-inline-comments
https://imgur.com/a/mMUYm9A
*/


1)

class Solution {
public:
    int numDecodings(string s) 
    {
        int n = s.size();
        if(n==0 or s[0]=='0')
            return 0;
        
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=1;i<n;i++)
        {
            int prev = stoi(s.substr(i-1,1));
            int curr = stoi(s.substr(i,1));
            
            if((prev==0 and curr==0) or (curr==0 and prev>2))
                return 0;
            else if(prev==0 or (prev*10+curr)>26)
                dp[i+1] = dp[i];
            else if(curr==0)
                dp[i+1] = dp[i-1];
            else
                dp[i+1] = dp[i] + dp[i-1];
        }
        return dp[n];
    }
};


2)

class Solution {
public:
    int numDecodings(string s) 
    {
        int n = s.size();
        if(n==0 or s[0]=='0')
            return 0;
        
        int prev=1;
        int curr=1;
        
        for(int i=1;i<n;i++)
        {
            int temp = curr;
            if(s[i]=='0')
                curr=0;
            if((s[i-1]=='2' and s[i]<='6') or s[i-1]=='1')
                curr+=prev;
            if(curr==0)
                return 0;
            prev = temp;
        }
        return curr;
    }
};
