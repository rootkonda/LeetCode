/*
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.



Typical dfs solution. Start our answer as given state of the board. 
Go thru the 8-directions for each 'E' no adjacent mines and add it to the temp stack and count the mines.
If there exists a mine, then just update the count in answer or else copy the temp stack into our main stack for further exploration.

*/


class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int rows=0;
    int cols=0;
    bool isSafe(int row,int col)
    {
        return row>=0 and col>=0 and row<rows and col<cols;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        rows = board.size();
        cols = board[0].size();
        vector<vector<char>> ans = board;
        set<pair<int,int>> vis;
        stack<vector<int>> coor;
        coor.push(click);
        while(!coor.empty())
        {
            vector<int> vec = coor.top();
            coor.pop();
            if(vis.count({vec[0],vec[1]})>0)
                continue;
            vis.insert({vec[0],vec[1]});
            if(board[vec[0]][vec[1]]=='M')
            {
                ans[vec[0]][vec[1]] = 'X';
                return ans;
            }
            int count=0;
            stack<vector<int>> temp;
            for(auto d :directions)
            {
                int r = vec[0]+d[0];
                int c = vec[1]+d[1];
                if(isSafe(r,c))
                {
                    if(board[r][c]=='M')
                        count++;
                    if(vis.count({r,c})==0)
                        temp.push({r,c});
                }
            }
            if(count>0)
                ans[vec[0]][vec[1]] = count+'0';
            else
            {
                while(!temp.empty())
                {
                    coor.push(temp.top());
                    temp.pop();
                }
                ans[vec[0]][vec[1]] = 'B';
            }
        }
        return ans;
    }
};
/*
[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
[1,2]
[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]
[3,0]
*/
