/*
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

 
https://leetcode.com/problems/regions-cut-by-slashes/discuss/205674/C%2B%2B-with-picture-DFS-on-upscaled-grid 
We upscale the grid to. [N*3][N*3] and start drawing a line in a blocks of 3.
Use dfs to traverse around and set each of them to 1 and when we cant traverse anymore then increment the regions.


*/
class Solution {
public:
  void dfs(vector<vector<int>>& g, int i, int j) 
  {
      if (i >= 0 && j >= 0 && i < g.size() && j < g.size() && g[i][j] == 0) 
      {
        g[i][j] = 1;
        dfs(g, i - 1, j), dfs(g, i + 1, j), dfs(g, i, j - 1), dfs(g, i, j + 1);
      }
}
int regionsBySlashes(vector<string>& grid, int regions = 0) 
{
  vector<vector<int>> g(grid.size() * 3, vector<int>(grid.size() * 3, 0));
  for (auto i = 0; i < grid.size(); ++i)
  {
      for (auto j = 0; j < grid.size(); ++j) 
      {
        if (grid[i][j] == '/') 
            g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1;
        if (grid[i][j] == '\\') 
            g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
      }
  }
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g.size(); ++j) if (g[i][j] == 0) dfs(g, i, j), ++regions;
  return regions;
}
};
