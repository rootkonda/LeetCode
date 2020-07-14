/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

*/


class Solution {
 public:
     int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
     {
        int area1=(D-B)*(C-A); // This will automatically take care of -ve x or y axis and gives total length and then find area.
        int area2=(H-F)*(G-E);
        int left=max(A,E),right=max(left,min(C,G));
        int bottom=max(F,B),up=max(bottom,min(H,D));
        int area3=(right-left)*(up-bottom);
        return area1+(area2-area3);
     }
 };
