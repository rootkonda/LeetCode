/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.


https://www.geeksforgeeks.org/trie-insert-and-search/

*/


class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct TrieNode 
    {
       struct TrieNode *children[26];
       bool isWord;
    };
    TrieNode* root;
    TrieNode* create()
    {
        struct TrieNode *node = new TrieNode();
        node->isWord = false;
        for(int i=0;i<26;i++)
            node->children[i]=NULL;
        return node;
    }
    WordDictionary() 
    {
        root = create();    
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i]-'a';
            if(node->children[index]==NULL)
                node->children[index] = create();
            node = node->children[index];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool helper(TrieNode* node,string word, int index)
    {
        if(node==NULL)
            return false;
        if(index==word.size())
            return node->isWord;
        
        char c = word[index];
        if(c=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(helper(node->children[i],word,index+1))
                    return true;
            }
        }
        else
        {
            return helper(node->children[c-'a'],word,index+1);
        }
        return false;
    }
    bool search(string word) 
    {
        return helper(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
