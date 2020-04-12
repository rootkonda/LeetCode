/**
Given two strings s and t , write a function to determine if t is an anagram of s.

1. Sort both strings and compare if they are equal.
2. Use map to store the string 1 and then check if characters in string 2 are present in map with exact count of characters.
**/

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> umap;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++)
        {
          umap[s[i]]++;
        }
        string res="";
        for(int i=0;i<t.length();i++)
        {
            if(umap.find(t[i])==umap.end())
                return false;
            if(umap[t[i]]>0)
            {
                umap[t[i]]--;
            }   
            else
                return false;
        }
        return true;
    }
};

