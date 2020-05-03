/**
Given a 2D board and a word, find if the word exists in the grid.  The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once

Backtracking algorithm:

There are four directions we can move on to form a word. So if a direction is valid, then check if the current character is same as word[0],word[1]...etc., Everytime we visit a position add it to a map. Clear the map after processing all the possible paths for this cell.

Secondly, while recursing make sure we do few things:
1. Add the unvisited position when we visit it for the first time.
2. Each recursive call will have next index to check with.
3. Erase the visited position from map if the answer is false because it may be needed for some other route.
4. At any call, if the index is greater than the given word size then there is path hence return true

**/





class Solution {
public:
    vector<vector<int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
    int m,n;
    set<pair<int,int>> visited;
    bool helper(vector<vector<char>>& board,string word,int index,int start,int end)
    {
        if(index>=word.size())
            return true;
        bool ans = false;
        for(auto dir : directions)
        {
            int row = start+dir[0];
            int col = end+dir[1];
            
            if(row>=0 and row<m and col<n and col>=0)
            {
                if(board[row][col]==word[index])
                {
                    if(visited.find({row,col})==visited.end())
                    {
                        visited.insert({row,col});
                        ans = helper(board,word,index+1,row,col);
                        if(ans)
                            return true;
                        else
                            visited.erase({row,col});
                    }
                }
            }
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        m = board.size();
        n = board[0].size();
        bool ans = false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    visited.insert({i,j});
                    ans = helper(board,word,1,i,j);
                    visited.clear();
                } 
                if(ans)
                    return true;
            }
        }
        return ans;
    }
};

// If there are similar chars then push them into vector and choose one of them and add it to visited set
// 

// A B C E
// S F E S
// A D E E

// ABCEFSADEESE
