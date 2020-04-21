/**
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

Since it is a sorted array of duplicate elements. We can use left-biased binary search to find the starting position of 1.

**/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int rows = binaryMatrix.dimensions()[0];
        int cols = binaryMatrix.dimensions()[1];
        int ans = INT_MAX;
        
        for(int i=0;i<rows;i++)
        {
            int row = i;
            int low = 0;
            int high = cols;
            while(low < high)
            {
                int mid = low+(high-low)/2;
                int x = row;
                int y = mid;//col
                if(binaryMatrix.get(x,y)<1)
                    low = mid+1;
                else
                    high = mid;
            }
            if(low != cols and binaryMatrix.get(row,low)==1)
                ans = min(ans,low);
        }
        if(ans!=INT_MAX)
            return ans;
        return -1;
    }
};
