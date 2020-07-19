/*

Whenever we see 'X' then we immediately have to check whether the previous character is not 'X' and also character above is not 'X' because we have calculated the answer.
As given in question, 'X' is always in the pattern of Nx1 or 1xN.
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) 
    {
        if(board.empty() or board[0].empty())
            return 0;
        int ans=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                ans+=board[i][j]=='X' and (i==0 or board[i-1][j]!='X') and (j==0 or board[i][j-1]!='X');
            }
        }
        return ans;
    }
};

/*
X . X . . X
X . . X . .
*/
