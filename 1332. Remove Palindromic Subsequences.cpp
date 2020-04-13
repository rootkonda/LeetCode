/**
Given a string s consisting only of letters 'a' and 'b'. In a single step you can remove one palindromic subsequence from s.

Return the minimum number of steps to make the given string empty.

A string is a subsequence of a given string, if it is generated by deleting some characters of a given string without changing its order.

A string is called palindrome if is one that reads the same backward as well as forward.

Since string only contains a and b. We can use two pointers to see if both characters are same, if not then then only options are either 1 if all characters from back to front match or 2 where it mismatch.

**/


class Solution {
public:
    int removePalindromeSub(string s) 
    {
        if(s.size()==0)
            return 0;
        int left=0,right=s.length()-1;
        while(left<=right)
        {
            if(s[left]!=s[right])
                break;
            left++;
            right--;
        }
        if(left>right)
            return 1;
        return 2;
    }
};