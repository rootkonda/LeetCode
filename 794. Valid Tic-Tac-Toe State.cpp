/*
A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.


Goal is to validate whether the given board is in valid state or not by compling with the given conditions.

*/


class Solution {
public:
    int getcount(vector<string>& b, char c) // Count of X and O characters
    {
        int res=0;
        for(auto str : b)
            res+=count(str.begin(),str.end(),c);
        return res;
    }
    bool win(vector<string>& b, char c) Check whether given char X or O is the winner.
    {
        for(int i=0;i<3;i++) // row check
            if(b[i][0]==c and b[i][1]==c and b[i][2]==c)
                return true;
        for(int j=0;j<3;j++) // col check
            if(b[0][j]==c and b[1][j]==c and b[2][j]==c)
                return true;
        
        return (b[0][0]==c and b[1][1]==c and b[2][2]==c) or (b[0][2]==c and b[1][1]==c and b[2][0]==c);//diagonal check
    }
    bool validTicTacToe(vector<string>& b) 
    {
        int cx = getcount(b,'X');
        int co = getcount(b,'O');
        int wx = win(b,'X');
        int wo = win(b,'O');
        
        if(co>cx) // Since X starts the count of X is always greater than O
            return false;
        if(wx and wo) // Both cant be winners so return false
            return false;
        return (wx ? cx==co+1 : wo ? cx==co : (cx==co+1 or cx==co)); //If wx is the winner, then only possibility is cx==co+1 and same when wo is the winner then cx==co
    }
};

/*

["XOX"
 "O O"
 " XX"]

*/
