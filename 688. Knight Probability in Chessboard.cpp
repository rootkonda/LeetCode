/**

On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

 
 
At each cell, we have 8 moves to make so if there is atleast 1 move to remain on the board then the probability is 1/8. 
Idea is to calculate the probabilities at each cell either from backwards or forward.

1. To calculate from backward, we have to traverse thru each cell and then 8 directions from that cell and then assign the current probability, which we calculated at the beginning.

2.Example, for 3x3 matrix and starts at 0,0 we can say it can make 2 moves to 1,2 and 2,1. It means when we are at 1,2 and 2,1 cells, it will update the cell 0,0 with 2 times 1/8. For next move, take the probability at each cell and then use it for further calculation at each cell.

In order to calculate forward, just make sure we initialize everything with zeroes except the given {r,c} position as 1.
At each cell, we move 8 directions and cells within boundary are updated with the probability. Say when we are 1,2 and 2,1 - we get 0,0 position twice so we multiply 2*.125 + whatever probability was already there at this cell.

Finallly, we have to traverse all cells and add all values to get the final answer.

**/

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) 
    {
        vector<vector<int>> directions{
            {-1,-2},{1,-2},{2,-1},{-2,-1},
            {2,1},{-2,1},{-1,2},{1,2}
        };
        vector<vector<double>> dp(N,vector<double>(N,1));
        
        while(K-- > 0)
        {
            vector<vector<double>> temp(N,vector<double>(N,0));
            for(int row=0;row<N;row++)
            {
                for(int col=0;col<N;col++)
                {
                    if(dp[row][col]==0)
                        continue;
                    double prob = dp[row][col]/8;
                    
                    for(auto dir : directions)
                    {
                        int r = row+dir[0];
                        int c = col+dir[1];
                        
                        if(r>=0 and r<N and c>=0 and c<N)
                            temp[r][c]+=prob;
                    }
                }
            }
            dp = temp;
        }
        return dp[r][c];
    }
};
