/**
  Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

  Note that the row index starts from 0.
  
  Create a vector of size rowIndex+1 and initialize it with 1's. Run a loop from 2 to rowIndex and then update vector for that
  row. Store the previous value in a temporary variable. 
**/
class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> ans(rowIndex+1,1);
        
        for(int i=2;i<=rowIndex;i++)
        {
            int prev=ans[0];
            for(int j=1;j<i;j++)
            {
                int temp=prev+ans[j];
                prev=ans[j];
                ans[j]=temp;
            }
        }
        return ans;
    }
};
