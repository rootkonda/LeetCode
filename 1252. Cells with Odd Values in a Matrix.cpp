/**
Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci]. For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.

Return the number of cells with odd values in the matrix after applying the increment to all indices.

Simple. Count the total updates to each row and total updates to each column into two maps. Loop thru row and col maps and update the cells. Finally run a loop over all cells and count the odd cells.
**/


class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices)
    {
        unordered_map<int,int> rmap,cmap;
        int count=0;
        int res[51][51]={0};
        
        for(int i=0;i<indices.size();i++)
        {
            rmap[indices[i][0]]++;
            cmap[indices[i][1]]++;
        }
        unordered_map<int, int>::iterator rit = rmap.begin();
        unordered_map<int, int>::iterator cit = cmap.begin();
        while(rit != rmap.end())
        {
            for(int i=0;i<m;i++)
            {
                res[rit->first][i]+=rit->second;
            }
            rit++;
        }
        while(cit != cmap.end())
        {
            for(int i=0;i<n;i++)
            {
                res[i][cit->first]+=cit->second;
            }
            cit++;
        }
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
            {
                if(res[i][j]%2!=0)
                    count++;
            }
        }
        rmap.clear();
        cmap.clear();
        return count;
    }
};
