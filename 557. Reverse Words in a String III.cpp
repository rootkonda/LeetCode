/**
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Simple and straightforward. Pick each word by using index and reverse them.
**/

class Solution 
{
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string reverseWords(string s) 
    {
        string ans="",temp="";
        int start=s.length()-1,end;
        for(int i=start;i>=0;i--)
        {
            if(s[i]==' ')
            {   
                for(int j=i+1,k=start;k>j;j++,k--)
                    swap(s[j],s[k]);
                start=i-1;
            }
        }
        for(int j=0,k=start;k>j;j++,k--)
            swap(s[k],s[j]);
        
        return s;
    }
};
