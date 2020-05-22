/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

1. For each character, keep track of the count in a map.
2. When we reach a window of size atleast k and the count of that character is atleast k then check for the max substring in that window.
3. Keep tracking the max length at every character.
*/


class Solution {
public:
    int helper(int left,int right,string s,unordered_map<char,int> count,int k)
    {
        int ans = 0;
        while(right-left>=k-1)
        {
            unordered_map<char,int>::iterator itr = count.begin();
            while(itr!=count.end()) // This loop is to check whether all characters in this window are atleast k
            {
                if(itr->second<k and itr->second!=0)
                    break;
                itr++;
            }
            if(itr==count.end()) // if all characters are atleast k
                ans = max(ans,right-left+1);
            count[s[left]]--; //Since reducing the window size so reduce the frequency of that character
            left++;// reduce the window size
        }
        return ans;
    }
    int longestSubstring(string s, int k) 
    {
        unordered_map<char,int> count;
        int res = 0;
        for(int i=0;i<s.size();i++)
        {
            count[s[i]]++;
            if(i>=k-1 and count[s[i]]>=k)
                res = max(res,helper(0,i,s,count,k));
        }
        return res;
    }
};
