/*
On an N x N board, the numbers from 1 to N*N are written boustrophedonically starting from the bottom left of the board, and alternating direction each row.  For example, for a 6 x 6 board, the numbers are written as follows:


You start on square 1 of the board (which is always in the last row and first column).  Each move, starting from square x, consists of the following:

You choose a destination square S with number x+1, x+2, x+3, x+4, x+5, or x+6, provided this number is <= N*N.
(This choice simulates the result of a standard 6-sided die roll: ie., there are always at most 6 destinations, regardless of the size of the board.)
If S has a snake or ladder, you move to the destination of that snake or ladder.  Otherwise, you move to S.
A board square on row r and column c has a "snake or ladder" if board[r][c] != -1.  The destination of that snake or ladder is board[r][c].

Note that you only take a snake or ladder at most once per move: if the destination to a snake or ladder is the start of another snake or ladder, you do not continue moving.  (For example, if the board is `[[4,-1],[-1,3]]`, and on the first move your destination square is `2`, then you finish your first move at `3`, because you do not continue moving to `4`.)

Return the least number of moves required to reach square N*N.  If it is not possible, return -1.

*/


class Solution {
public:
    pair<int,int> get(int x,int N)
    {
        int row = N-1-(x-1)/N; // N- is to start from the last row.
        int col = (x-1)%N;
        return (row%2==N%2) ? make_pair(row,N-col-1) : make_pair(row,col);
        // Given N is odd or even, as alternating rows will have to be considered so N-col-1 is nothing but coming from the back
        // If you dont have to come from back then just return row and col.
    }
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int N = board.size();
        queue<int> que;
        que.push(1);//start with 1 as given
        int ans = 0;
        vector<bool> vis(410,false);
        while(!que.empty())
        {
            int sz = que.size();
            while(sz--)
            {
                int box = que.front();
                que.pop();
                if(N*N == box) // At any point if we have reached the end of the board(N*N) then return the steps taken starting from 1
                    return ans;
                for(int i=1;i<=6;i++)
                {
                    if(box+i>N*N) // If the box+i value is higher the possible box value
                        break;
                    auto xy = get(box+i,N); // gives us the board coordinates based on the box value.
                    if(!vis[box+i]) // If a square is NOT visited
                    {
                        if(board[xy.first][xy.second]>0) // When there is +ve number
                            que.push(board[xy.first][xy.second]); // push it to queue for further exploration of all possible 1 to 6 values from that box
                        else
                            que.push(box+i);
                        vis[box+i]=true; // As we are going to explore we can set visited to true
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

/*
4 -1
-1 3
*/
