/**
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

Questions related to alphabets,we can use alphabet array of 26 and solved this problem. This technique can be used in many places involving alphabets. 
**/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int a[26];
        memset(a,0,sizeof(a));
        for(auto m : magazine)
            a[m-'a']++;
        for(auto r : ransomNote)
        {
            if(a[r-'a']>0)
                a[r-'a']--;
            else
                return false;
        }
        return true;
    }
};
