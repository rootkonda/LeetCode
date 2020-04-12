/**
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

Binary search. Instead of fixed target value, it comes from guess method.
**/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) 
    {
        long long low=1,high=n,mid,res;
        while(low<=high)
        {
            mid=(low+high)>>1;
            res=guess(mid);
            if(res==0)
                return mid;
            else if(res==-1)
                high=mid-1;
            else if(res==1)
                low=mid+1;
        }
        return n;
    }
};
