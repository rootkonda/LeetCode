/**
Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

Simple.

1. string to int - stoi()
2. int to char - (char)(val+96)
3. ((char)((s[idx]-48)+96)) - char format of int to number and then char again.

**/

class Solution 
{
public:
    string freqAlphabets(string s) 
    {
        int idx=0,val;
        string res="";
        while(idx<s.length())
        {
            if(s[idx]=='#')
            {
               string t;
               t.push_back(s[idx-2]);
               t.push_back(s[idx-1]);
               val=stoi(t);
               res.pop_back();
               res.pop_back();
               res.push_back((char)(val+96));
            }
            else
               res.push_back((char)((s[idx]-48)+96));
            idx++;
        }
        return res;
    }
};

