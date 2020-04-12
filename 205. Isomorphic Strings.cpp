/**

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
You may assume both s and t have the same length.

Approach:
Maintain bi-directional relationship between two characters using two maps. Everytime we see a character in s, check both maps and make sure it maps to the same characters.
**/


class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_map<char,char> lmap;
        unordered_map<char,char> rmap;
        for(int i=0;i<s.size();i++)
        {
            if(lmap.find(s[i])==lmap.end() and rmap.find(t[i])==rmap.end())
            {
                lmap[s[i]]=t[i];
                rmap[t[i]]=s[i];
            }
            else if(lmap[s[i]]!=t[i] and rmap[t[i]]!=s[i])
                return false;
        }
        return true;
    }
};
