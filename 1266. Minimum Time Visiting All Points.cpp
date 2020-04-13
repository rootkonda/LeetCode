/**
On a plane there are n points with integer coordinates points[i] = [xi, yi]. Your task is to find the minimum time in seconds to visit all points.

You can move according to the next rules:

In one second always you can either move vertically, horizontally by one unit or diagonally (it means to move one unit vertically and one unit horizontally in one second).
You have to visit the points in the same order as they appear in the array.

Take pairs of points at a time. Take the distance between x and y coordinates. Whichever is bigger will be added to time taken to reach from one point to another.
**/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        vector<int> p1,p2;
        int time=0,x=0,y=0;
        for(int i=0;i<points.size()-1;i++)
        {
            p1=points[i];
            p2=points[i+1];
            
            if(p2[0]>p1[0])
                x+=(p2[0]-p1[0]);
            else
                x+=(p1[0]-p2[0]);
            
            if(p2[1]>p1[1])
                y+=(p2[1]-p1[1]);
            else
                y+=(p1[1]-p2[1]);
           
            if(x>=y)
                time+=x;
            else
                time+=y;
            
            x=0;y=0;
        }
        return time;
    }
};
