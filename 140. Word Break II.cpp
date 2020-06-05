/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

For each prefix iterate thru the trie and prepare the list of valid words and add them to vector.
All possible words starting index i will be stored in a map for that index and we return this vector for the parent call.

https://leetcode.com/problems/word-break-ii/discuss/44262/My-C%2B%2B-DP%2BDFS-solution-(4ms)
https://leetcode.com/problems/word-break-ii/discuss/507365/C%2B%2B-short-and-fast%3A-DFS-%2B-hash-map-for-DP-(speed-95mem-94)

*/



class Solution {
public:
    struct Trie
    {
        bool isWord=false;
        Trie* children[26];
        Trie()
        {
            for(int i=0;i<26;i++)
                children[i]=NULL;
        }
    };
    Trie* root=NULL;
    map<int,vector<string>> dp;
    void insert(string& s)
    {
        Trie* curr = root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->children[s[i]-'a']==NULL)
                curr->children[s[i]-'a'] = new Trie();
            curr = curr->children[s[i]-'a'];
        }
        curr->isWord=true;
    }
    vector<string> search(Trie* curr,string& s,int idx)
    {
        if(idx==s.size())
            return vector<string>(1,"");
        if(dp.find(idx)!=dp.end())
            return dp[idx];
        string temp="";
        vector<string> ans;
        for(int i=idx;i<s.size();i++)
        {
            if(curr!=NULL and curr->children[s[i]-'a']!=NULL)
            {
                temp.push_back(s[i]);
                if(curr->children[s[i]-'a']->isWord)
                {
                    vector<string> output = search(root,s,i+1);
                    for(auto suffix : output)
                        ans.push_back(temp+(suffix.size()>0?" ":"")+suffix);
                }
            }
            curr = (curr!=NULL ? curr->children[s[i]-'a'] : curr);
        }
        return dp[idx]=ans;
    }
    vector<string> wordBreak(string s, vector<string>& dict)
    {
        root = new Trie();
        for(auto str:dict)
            insert(str);
        
        return search(root,s,0);
    }
};
