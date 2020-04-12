/**
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
Note:

You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet

Simple. string::npos and transform methods.
**/

class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
        string rows[3];
        rows[0]="QWERTYUIOP";
        rows[1]="ASDFGHJKL";
        rows[2]="ZXCVBNM";
        vector<string> ans;
        string str;
        for(auto s :  words)
        {
            int i=1;
            str=s;
            std::transform(str.begin(), str.end(),str.begin(), ::toupper);
            if(rows[0].find(str[0])!=string::npos)
            {
               for(i=1;i<s.size();i++)
                {
                    if(rows[0].find(str[i])==string::npos)
                        break;
                }
                if(i==s.size())
                    ans.push_back(s);
            }
            else if(rows[1].find(str[0])!=string::npos)
            {
                for(i=1;i<s.size();i++)
                {
                    if(rows[1].find(str[i])==string::npos)
                        break;
                }
                if(i==s.size())
                    ans.push_back(s);
            } 
            else
            {
                for(i=1;i<s.size();i++)
                {
                    if(rows[2].find(str[i])==string::npos)
                        break;
                }
                if(i==s.size())
                    ans.push_back(s);
            }
        }
        return ans;
    }
};
