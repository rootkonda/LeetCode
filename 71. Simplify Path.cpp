/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.


*/


class Solution {
public:
    string simplifyPath(string path) 
    {
        if(path.size()==0)
            return path;
        stack<string> stk;
        string ans="";
        int i=0;
        while(i<path.size())
        {
            string temp="";
            int count=0;
            i = (i!=0) ? i-1 : 0;
            while(count<2 and i<path.size()) // Get the string between / and /
            {
                if(path[i]=='/')
                    count++;
                else
                    temp.push_back(path[i]);
                i++;
            }
            if(temp==".." and !stk.empty()) // if string is .. then pop the last directory because we are going up one level
                stk.pop();
            else if(temp.size() and (isalpha(temp[0]) or temp.size()>2)) // if the string is of alphabets then add it to the stack
                stk.push(temp);     
        }
        if(stk.empty()) // empty means return /
            return "/";
        while(!stk.empty())
        {
            ans.insert(0,"/"+stk.top());
            stk.pop();
        }
        return ans;
    }
};


/*
"/home/"
"/../"
"/home//foo/"
"/a/./b/../../c/"
"/a/../../b/../c//.//"
"/a//b////c/d//././/.."
"/..."
"/.../"
*/
