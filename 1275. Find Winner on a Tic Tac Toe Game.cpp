/**
Tic-tac-toe is played by two players A and B on a 3 x 3 grid.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player A always places "X" characters, while the second player B always places "O" characters.
"X" and "O" characters are always placed into empty squares, never on filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which A and B play.

Return the winner of the game if it exists (A or B), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".

You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first.

Simple and straightforward.
**/

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) 
    {
        char a[3][3];
        bool A=true;
        int count=9;
        int countX=0;
        int countO=0;
        for(int i=0;i<moves.size();i++)
        {
            if(A)
            {
                a[moves[i][0]][moves[i][1]]='X';
                A=false;
            }
            else
            {
                a[moves[i][0]][moves[i][1]]='O';
                A=true;
            }
            count--;
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(a[i][j]=='X')
                    countX++;
                if(a[i][j]=='O')
                    countO++;
            }
            if(countX==3)
                return "A";
            else if(countO==3)
                return "B";
            countX=0;
            countO=0;
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(a[j][i]=='X')
                    countX++;
                if(a[j][i]=='O')
                    countO++;
            }
            if(countX==3)
                return "A";
            else if(countO==3)
                return "B";
            countX=0;
            countO=0;
        }
        if(a[0][0]==a[1][1] and a[2][2]==a[1][1] and a[0][0]=='X')
            return "A";
        if(a[0][2]==a[1][1] and a[2][0]==a[1][1] and a[0][2]=='X')
            return "A";
        if(a[0][0]==a[1][1] and a[2][2]==a[1][1] and a[0][0]=='O')
            return "B";
        if(a[0][2]==a[1][1] and a[2][0]==a[1][1] and a[0][2]=='O')
            return "B";
        if(count==0)
            return "Draw";
        else
            return "Pending";
    }
};
