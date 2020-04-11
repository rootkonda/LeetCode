/**
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  An input string is valid if:

  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.
  Note that an empty string is also considered valid.
  
  Approach:
  
  Can be done using Stack. This is similar approach using array. Keep storing the opening brackets in an array.
  And also keep track of last open bracket index. When there is a closing bracket compare it with the last open bracket. **/
  
class Solution {
public:
    bool isValid(string s) 
    {
        int idx=-1;
        if(s=="")
            return true;
        char t[s.length()];
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
            {
               idx++;
               t[idx]=s[i];
            }
            else if(idx>-1)
            {
                if((s[i]==')' and t[idx]=='(') or (s[i]==']' and t[idx]=='[') or (s[i]=='}' and t[idx]=='{'))
                {
                    t[idx]='\0';
                    --idx;
                }
                else
                    return false;
            }
            else
                return false;
        }
        if(idx<0)
            return true;
        return false;
    }
};
