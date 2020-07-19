/*
A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.
*/

class Solution 
{
public:
    vector<char> st{'a','b','c'};
    vector<string> ans;
    void backtrack(string curr,int n,int k)
    {
        if(ans.size()>=k)
            return;
        if(n==0)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<3;i++)
        {
            if(curr.empty() or (curr.size()>0 and curr.back()!=st[i]))
            {
                curr.push_back(st[i]);
                backtrack(curr,n-1,k);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) 
    {
        backtrack("",n,k);
        return ans.size()>=k ? ans[k-1] : "";
    }
};
