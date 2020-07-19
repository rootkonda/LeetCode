/*
In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.



Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.
1. row - row number, which is equal to the closest power of 2. Instead of ceil add 1 in order to avoid issues when given 'n' is a power of 2
2. st - starting number in the current row based on given n
3. ans - This will be of size log2(n)
4. start filling the ans from the back
5. For each row starting from the given n's row/level, do the following:
		a. Find the number of nodes in this row
		b. Starting from the parent, iteratively subtract 2 nodes for each parent and when we have less than 2 nodes then we have reached the right parent for current n
		c. Add this to the ans
6. Next row will be the one above and its starting number will be st/=2
7. The new 'n' will be the parent we found in this current row.
8. Repeat this process until we reach a starting number 1
*/

class Solution {
public:
    vector<int> pathInZigZagTree(int n) 
    {
        int row = log2(n)+1; 
        int st = pow(2,row-1);
        vector<int> ans(row,0);
        ans[--row] = n;
        while(st!=1)
        {
            int pos = n-st+1; 
            int parent = st-1; 
            while(pos>2) 
            {
                parent--;
                pos-=2;
            }
            ans[--row]=parent;
            st/=2;
            n = parent; 
        }
        return ans;
    }
};
