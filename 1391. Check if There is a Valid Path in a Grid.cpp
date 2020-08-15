/*
Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.


https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/discuss/547225/C%2B%2B-with-picture%3A-track-direction-%2B-upscaled-grid
*/

class Solution {
public:
    vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
unordered_map<int, int> turns[7]{{}, 
    {{0, 0}, {1, 1}}, {{2, 2}, {3, 3}}, {{0, 2}, {3, 1}}, 
    {{3, 0}, {1, 2}}, {{0, 3}, {2, 1}}, {{2, 0}, {1, 3}}};
bool trace(vector<vector<int>> &g, int dir) {
    int i = 0, j = 0, m = g.size(), n = g[0].size();
    while(min(i, j) >= 0 && i < m && j < n) {
        auto road = g[i][j];
        if (turns[road].count(dir) == 0)
            return false;
        if (i == m - 1 && j == n - 1)
            return true;
        dir = turns[road][dir];
        i += dirs[dir].first, j += dirs[dir].second;
        if (i == 0 && j == 0)
            return false;
    }
    return false;        
}
bool hasValidPath(vector<vector<int>>& g) {
    return trace(g, 0) || trace(g, 1) || trace(g, 2) || trace(g, 3);
}
};
