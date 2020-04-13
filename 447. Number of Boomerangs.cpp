/**
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

https://www.mathsisfun.com/algebra/distance-2-points.html

For each point, loop thru all points and find the difference between two points and store it in a map. For each matching distance in map, they can be arranged in two ways.
**/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int count=0;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<int,int> distance;
            for(int j=0;j<points.size();j++)
            {
                int d=pow(points[j][1]-points[i][1],2)+pow(points[j][0]-points[i][0],2);
                if(distance[d]>0)
                    count+=distance[d]<<1;
                distance[d]++;
            }
        }
        return count;
    }
};
