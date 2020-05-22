/*
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

 

Idea is to use the two maps or one map and one set and keep track of the visited characters in pattern and given word.
Whenever there is a character in the word which is new but at that point the corresponding pattern character was already used then immediately we can say the given string is invalid.

*/
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        int n = (int)pattern.size();
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            int j;
            unordered_map<char,char> wp; // word characters to pattern characters
            unordered_map<char,char> pw; // pattern characters to word characters
            string temp="";
            for(j=0;j<n;j++)
            {
                if(wp.count(words[i][j])>0) // If character in the word already in map, then reuse the same character.
                    temp.push_back(wp[words[i][j]]);
                else
                { // When the current character in word is new.
                    wp[words[i][j]] = pattern[j]; // Add the mapping
                    if(pw.count(pattern[j])>0) // If the pattern character was already used then it means we came across invalid string. Whenever we encounter a new character in word, then it should be available for use
                        break;
                    temp.push_back(pattern[j]); // Append it to temp pattern
                    pw[pattern[j]] = words[i][j]; // Update the pattern map that this pattern was used.
                }
            }
            if(temp.compare(pattern)==0) // If temp pattern and actual pattern matches then thats the valid string
                ans.push_back(words[i]);
        }
        return ans;
    }
};
