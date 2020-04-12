/**
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1

Approach:

Use alphabet array of 26 and update the unique characters with indices and others with -ve numbers. Run another loop to find the smallest +ve number in alphabet array of 26.
**/

class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int a[26];
        memset(a,-1,sizeof(a));
        int mn=INT_MAX;
        for(int i=0;i<s.length();i++)
        {
            if(a[s[i]-'a']==-1)
                a[s[i]-'a']=i;
            else
                a[s[i]-'a']=-2;
        }
        for(auto i:a)
        {
            if(i>-1 and mn>i)
                mn=i;
        }
        if(mn==INT_MAX)
            return -1;
        return mn;
    }
};
