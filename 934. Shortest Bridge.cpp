/*
In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

Explanation
-----------
1. There are two islands to connect. So firstly find all the coordinates of the first island.
2. Mark all the coordinates of first island as visited.
3. For each coordinate, start exploring 4 directions only if those new coordinates does not belong to first island or not yet visited.

We use DFS to find all coordinates of first island and BFS to explore starting from first island. The first 1 that comes will be the answer. So keep track of the breadth and finally return the answer minus one because we are over counting by 1.
*/


class Solution {
  public:
      vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
      queue<pair<int,int>> que;
      int n;
      int shortestBridge(vector<vector<int>>& A)
      {
          n = A.size();
          int k=0;
          int row=-1,col=-1;
          vector<vector<int>> island(n,vector<int>(n,0));
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<n;j++)
              {
                  if(A[i][j]==1)
                  {
                      row = i;
                      col = j;
                      break;
                  }
              }
              if(row!=-1)
                  break;
          }
          stack<pair<int,int>> stk;
          stk.push({row,col});
          while(!stk.empty())
          {
              pair<int,int> p = stk.top();
              stk.pop();
              if(island[p.first][p.second]==0)
                  que.push(p);
              else
                  continue;
              island[p.first][p.second] = 1;
              for(k=0;k<4;k++)
              {
                  int r = p.first+dir[k][0];
                  int c = p.second+dir[k][1];
                  if(r>=0 and r<n and c>=0 and c<n)
                  {
                      if(A[r][c]==1 and island[r][c]==0)
                      {
                          stk.push({r,c});
                      }
                  }
              }
          }
          int ans = 0;
          while(!que.empty())
          {
              int sz = que.size();
              ans++;
              while(sz--)
              {
                  pair<int,int> itr = que.front();
                  que.pop();
                  island[itr.first][itr.second]=1;
                  for(k=0;k<4;k++)
                  {
                      int r = itr.first+dir[k][0];
                      int c = itr.second+dir[k][1];
                      if(r>=0 and r<n and c>=0 and c<n)
                      {
                          if(A[r][c]==1 and island[r][c]==0)
                            return ans-1;
                          else if(A[r][c]==0 and island[r][c]==0)
                          {
                              island[r][c]=1;
                              que.push({r,c});
                          }
                      }
                  }
              }  
          }
          return ans;
      }
  };
