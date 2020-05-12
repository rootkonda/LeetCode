/*
Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 
*/

class Solution {
public:
    int scoreOfParentheses(string S) 
    {
        int balance=0;
        int ans = 0;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='(')
                balance++; //For every opening bracket increase the balance
            else
            {
                balance--; // when closing bracket is there then decrease the balance.
                if(S[i-1]=='(')
                    ans+=1<<balance;// left shift to multiply by 2
            }
        }
        return ans;
    }
};
