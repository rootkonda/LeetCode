/**
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Idea is to keep track of possible right and left paranthesis counts.
For each character:
1. If it is left paranthesis, increment leftcount otherwise, it can either be * or ) so decrement leftcount by assuming * as )
2. If it is not right paranthesis, then increment the rightcount. So for example "(" the possible low count is 1 and possible high count is also 1.
3. If there is *, then decrement leftcount and increment the rightcount.
4. If the rightcount<0 then it means there are more ) characters before * or ( characters so it is invalid.
5. When there are two many * leftcount will become -ve so make sure to keep it +ve.
**/

class Solution 
{
public:
    bool checkValidString(string s) 
    {
        int leftcount=0,rightcount=0;
        
        for(auto c : s)
        {
            if(c==')')
                rightcount--;
            else
                rightcount++;
            if(c=='(')
                leftcount++;
            else
                leftcount--;
            if(rightcount<0)
                break;
            leftcount = max(leftcount,0);
        }
        if(leftcount==0)
            return true;
        return false;
    }
};
