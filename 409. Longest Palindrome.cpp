/**
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Approach:

Read the string and update character count in alphabet array of 60 (lower and upper case letters). Check each character count for:
1. If count%2 == 0 then it means add 2 to length of palindrome.
2. Otherwise, add number of 2's to length of palindrome.
3. Finally add 1 to length if there was odd character count.
**/


class Solution {
public:
    int longestPalindrome(string s) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int a[60];
        memset(a,0,sizeof(a));
        int sum=0;
        int add=0;
        for(auto c : s)
            a[c-'A']++;
        
        for(int i=0;i<60;i++)
        {
            if(a[i]>0)
            {
                if(a[i]%2==0)
                    sum+=a[i];
                else
                {
                    sum+=(a[i]/2)*2;
                    add=1;
                }  
            }
        }
        return sum+add;  
    }
};

//cdcacdc
//a 3 
//b 3
//c 4
//d 2
