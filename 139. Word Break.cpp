/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Standard Trie Data Structure. To search a prefix word:
1. Whenever we find a word in the trie, we start our recursion from the next character.
2. Whenever we don't find a character in the trie, immediately return false.
3. We use dp array to store the results of a substrings we tried, mainly when they are false it will help us not to traverse thru them again.


*/
class Solution {
public:
    unordered_map<int,bool> dp;
    struct Trie
    {
        Trie* children[26];
        bool isWord=false;
        Trie()
        {
           for(int i=0;i<26;i++)
                children[i]=NULL; 
        }  
    }*root;
    
    void insert(string& str)
    {
        Trie* curr=root;
        for(int i=0;i<str.size();i++)
        {
            if(curr->children[str[i]-'a']==NULL)
                curr->children[str[i]-'a'] = new Trie();
            curr = curr->children[str[i]-'a'];
        }
        curr->isWord=true;
    }
    
    bool search(Trie* curr,string& str,int idx)
    {
        if(idx==str.size())
            return true;
        if(dp.count(idx))
            return dp[idx];
        for(int i=idx;i<str.size();i++)
        {
            if(curr->children[str[i]-'a']==NULL)
                return false;
            if(curr->children[str[i]-'a']->isWord)
            {
                dp[i+1] = search(root,str,i+1);
                if(dp[i+1])
                    return true;
            }
            curr = curr->children[str[i]-'a'];
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& dict)
    {
        root = new Trie();
        for(auto str : dict)
            insert(str);
        return search(root,s,0);
    }
};
