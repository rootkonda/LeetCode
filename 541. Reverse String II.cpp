/**
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Simple and straightforward.
**/

class Solution {
public:
    string reverseStr(string s, int k) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int start=0,end=start+2*k;
        for(int i=0;end<=s.length();i++)
        {
            for(int j=start,m=start+k-1;m>j;j++,m--)
                swap(s[j],s[m]);
            start=end;
            end=start+2*k;
        }
        if(start<s.length())
        {
            int m=s.length()-1;
            if(start+k<=s.length())
                m=start+k-1;
            for(int j=start;m>j;j++,m--)
                swap(s[j],s[m]);
        }
        
        return s;
    }
};
