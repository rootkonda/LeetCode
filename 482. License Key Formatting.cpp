/**
You are given a license key represented as a string S which consists only alphanumeric character and dashes. The string is separated into N+1 groups by N dashes.

Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which could be shorter than K, but still must contain at least one character. Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.

Note:
The length of string S will not exceed 12,000, and K is a positive integer.
String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
String S is non-empty.

Approach:
Find the number of groups to be formed by /K and length of first group by %K. Form the first group and other groups separately.

**/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) 
    {
        string ans="";
        int count=0;
        
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='-')
                count++;
            else if(S[i]>=97 and S[i]<=122)
                S[i]-=32;
        }
        int first = (S.size()-count)%K;
        int groups = (S.size()-count)/K;
        int i=0;
        count=0;
        while(count<first)
        {
            if(i<S.size() and S[i]!='-')
            {
                ans+=S[i];
                count++;
            }
            i++;
        }
        if(ans!="" and ans.size()<S.size())
            ans+='-';
        count=0;
        while(i<S.size())
        {
            if(count>=K)
            {
                count=0;
                groups--;
                if(groups>0)
                    ans+='-';
            }   
            if(S[i]!='-')
            {
                ans+=S[i];
                count++;
            }
            i++;
        }
        
        return ans;
    }
};
