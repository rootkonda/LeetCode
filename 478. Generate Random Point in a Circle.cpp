/*
Given the radius and x-y positions of the center of a circle, write a function randPoint which generates a uniform random point in the circle.

Note:

input and output values are in floating-point.
radius and x-y position of the center of the circle is passed into the class constructor.
a point on the circumference of the circle is considered to be in the circle.
randPoint returns a size 2 array containing x-position and y-position of the random point, in that order.

https://stats.stackexchange.com/questions/394306/cant-understand-why-rejection-sampling-works
https://meyavuz.wordpress.com/2018/11/15/generate-uniform-random-points-within-a-circle/
*/

class Solution {
private:
    double r, x, y;
public:
    // [1,0,0]: 1 is radius, 0,0: is the center of a circle
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        while(true){
            double x1 = (2 * 1.0 * rand() / RAND_MAX - 1.0) * r;
            double y1 = (2 * 1.0 * rand() / RAND_MAX - 1.0) * r;
            if(x1 * x1 + y1 * y1 <= r * r) {
                return {x + x1, y + y1};
            }
        }
    }
};
