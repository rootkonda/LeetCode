/**
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Two pointer approach.

**/

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        for(int i=0,j=s.size()-1;j>i;j--,i++)
            swap(s[i],s[j]);
    }
};
