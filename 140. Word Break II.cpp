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


DFS with MaxLen
---------------
class Solution {
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) 
        {
            int max_len = 0;
            unordered_set<string> dict;
            for(string& str : wordDict)
            {
                dict.insert(str);
                max_len = max(max_len, (int)str.length());
            }

            unordered_map<int, vector<string>> mp;
            return break_word(s, 0, dict, max_len, mp);
        }

    protected:
        vector<string> break_word(  const string& s, int n, unordered_set<string>& dict, 
                                    int max_len, unordered_map<int, vector<string>>& mp)
        {
            if(mp.count(n)) return mp[n];

            string str;
            for(int i = n; i < s.length() && str.length() <= max_len; ++i)
            {
                str += s[i];
                if(dict.count(str))
                {
                    if(i == s.length()-1)
                        mp[n].push_back(str);
                    else
                    {
                        vector<string> vs = break_word(s, i+1, dict, max_len, mp);
                        for(auto& a : vs) mp[n].push_back(str + " " + a);
                    }
                }
            }
            return mp[n];
        }
};


DP+DFS+Max and Min Len
-----------------------
class Solution {
private: //DFS path build function
    void buildPath(bool isBreakable[], string &s, int pos, vector<string> &res, string curP, unordered_set<string>& wordDict, int minlen, int maxlen)
    {
        int i, len = s.size();
        for(i =minlen; i<= min(maxlen, len - pos); ++i)
            if( isBreakable[pos+i] && wordDict.count(s.substr(pos,i)) ) 
                if(pos+i == len) res.push_back(curP + s.substr(pos,i));
                else buildPath(isBreakable, s, pos+i, res, curP + s.substr(pos,i) + " ", wordDict, minlen, maxlen);
    }
    
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int sSize = s.size(), len, i, minlen = INT_MAX, maxlen = INT_MIN;
        vector<string> res;
        bool isBreakable[sSize+1];
        fill_n(isBreakable, sSize+1, false);
            
        for (string word : wordDict) { // find the minimum and maximum word length 
            minlen = min(minlen, (int)word.length());
            maxlen = max(maxlen, (int)word.length()); 
        }        
        //DP to build isBreakable
        for(i=sSize-minlen, isBreakable[sSize]= true; i>=0; --i)
            for(len=minlen; len<=min(maxlen, sSize-i); ++len)
            {
                if(isBreakable[i+len] && wordDict.count(s.substr(i,len)) ) {isBreakable[i] = true; break;}
            }
        //if breakable, do DFS path building
        if(isBreakable[0]) buildPath(isBreakable, s, 0, res, "", wordDict, minlen, maxlen);
        return res;
    }
};
