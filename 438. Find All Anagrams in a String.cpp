/**
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Sliding Window approach. Decrement and increment count for each new window.
**/


class Solution {
public:
    bool match(vector<int>& a, vector<int>& b)
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s2, string s1) 
    {
        if(s2.size()<s1.size())
            return {};
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> p(26,0);
        int left,j;
        int limit = (int)s1.size();
        int start = -1;
        if(limit==0)
            return {};
        if(s2.size()==0)
            return {};
        vector<int> temp(26,0);
        vector<int> ans;
        for(int i=0;i<limit;i++)
        {
            char c = s1[i];
            p[s1[i]-'a']++;
            temp[s2[i]-'a']++;
        }
            
        
        int len = (int)s2.size();
        for(int i=0;i<len-limit;i++)
        {
            if(match(p,temp))
                ans.push_back(i);
            temp[s2[i+limit]-'a']++;
            temp[s2[i]-'a']--;
        }
        if(match(p,temp))
            ans.push_back(len-limit);
        return ans;
    }
};

//aaabbbcc
