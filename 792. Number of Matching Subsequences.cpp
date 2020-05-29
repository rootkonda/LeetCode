/*

Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].

Expalanation
-------------
Just straightforward. For each word, just check against the given string whether its a subsequence or not. Only thing is make sure to store the given words in a map and then run a loop on that map to avoid duplicates in words array and that would result in TLE.
*/


class Solution {
public:
    bool isSubSeq(string& a, string b)
    {
        int i=0;
        int j=0;
        int n = (int)b.size();
        int m = (int)a.size();
        while(i<m and j<n)
        {
            if(a[i]==b[j])
                i++,j++;
            else
                i++;
        }
        return (j==n);      
    }
    int numMatchingSubseq(string S, vector<string>& words) 
    {
        int count = 0;
        unordered_map<string,int> str;
        for(auto w: words)
            str[w]++;
        
        for(auto itr : str)
        {
            if(isSubSeq(S,itr.first))
                count+=itr.second;
        }
        return count;
    }
};
