/**
Given an integer n. No-Zero integer is a positive integer which doesn't contain any 0 in its decimal representation.

Return a list of two integers [A, B] where:

A and B are No-Zero integers.
A + B = n
It's guarateed that there is at least one valid solution. If there are many valid solutions you can return any of them.

Two pointers - left and right for start and end-1.
Increment left and right until both doesnt not contain zero.

**/

class Solution {
public:
    int hasZero(int inp)
    {
        int j;
        if (inp==0) 
            return 1;
        while (inp>0)
        {
            j=inp%10;
            if(j==0) 
                return 1;
            inp/=10;
        }
        return 0;
    }
    vector<int> getNoZeroIntegers(int input) {
        int left=1;
        int right=input-1;
        while (hasZero(right)||hasZero(left))
        {
            left++;
            right--;
        }
        return {left,right};
    }
};
