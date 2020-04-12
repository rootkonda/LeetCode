/**

You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

Simple. modulus n by 4. This works because any number from 1 to 3 mod 4 leaves a remainder and next player can pick that remaining stones.

**/


class Solution 
{
public:
    bool canWinNim(int n) 
    {
        if(n%4!=0)
            return true;
        return false;
    }
};
