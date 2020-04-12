/**

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Maintain two maps - one for word to pattern letter and vice versa. For every word, check word map and pattern map if its empty and then insert it in both maps. If not empty, then compare the new word with the word for this pattern. If they are different, then it doesnt match the pattern.

**/


class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        unordered_map<char,string> words;
        unordered_map<string,char> mp;
        string temp="";
        int idx=0,count=0;
        str=str+" ";
        for(int i=0;i<str.length();i++)  
        {
            if(str[i]==' ' and temp.length()>0)
            {
                count++;
                if(words.find(pattern[idx])==words.end() and mp.find(temp)==mp.end())
                {
                    words[pattern[idx]]=temp;
                    mp[temp]=pattern[idx];
                }
                else if(words[pattern[idx]].compare(temp)!=0)
                    return false;

                temp="";
                idx++;
            }
            else if(str[i]!=' ')
                temp+=str[i];

        }
        if(count!=pattern.length())
            return false;
        return true;
    }
};
