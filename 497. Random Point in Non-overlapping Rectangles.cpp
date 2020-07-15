/*
Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Note:

An integer point is a point that has integer coordinates. 
A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.

*/
class Solution {
public:
    vector<int> points;
    vector<vector<int>> rec;
    int n=0;
    Solution(vector<vector<int>>& rects) 
    {
        rec = rects;
        n = rects.size();
        for(int i=0;i<n;i++)
        {
            int a = abs((rec[i][2]-rec[i][0]+1)*(rec[i][3]-rec[i][1]+1)); // +1 gives us the total number of points i.e. to include zero also. Basically we are merging all the points in all rectangles
            points.push_back(i==0 ? a : points[i-1]+a);
        }
    }
    
    vector<int> pick() 
    {
        int randarea = rand()%points[n-1];
        int idx = upper_bound(points.begin(),points.end(),randarea)-points.begin();
        // when we look for a point and which rectangle it belongs we use binary search. 
        // 0,1,2,3 (4 points) 
        int x1 = rec[idx][0];
        int x2 = rec[idx][2];
        int y1 = rec[idx][1];
        int y2 = rec[idx][3];
        
        return {(x1+rand()%(x2-x1+1)),(y1+rand()%(y2-y1+1))};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 
 0 0 1 1
 
 
 */
