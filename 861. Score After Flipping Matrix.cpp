/*
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.


*/

class Solution {
 public:
     int getDecimal(vector<vector<int>>& A,int row,int c)
     {
         int mask = 1;
         int result = 0;
         int shift = 0;
         for(int col=c;col>=0;col--)
         {
             if((A[row][col] & mask))
                result|=(1<<shift); // shift 1 by x times and it to the existing result value
            shift++; // getting ready for the next bit position if there is 1.
         }
         return result;
     }
     int matrixScore(vector<vector<int>>& A)
     {
         int m = A.size();
         int n = A[0].size();
         int score = 0;
         int ans = 0;
         for(int row=0;row<m;row++) // For each row set MSB to 1 so it means all other cells will be toggled in that row. But this will anyway give us the max value as the MSB is 1
         {
             if(A[row][0]==1) // If MSB is already 1 then skip this row because it is already at max value.
             {
                 score+=getDecimal(A,row,n-1);//Get the decimal value for each row and update the total score.
                 continue;
             }
             for(int col=0;col<n;col++)
                 A[row][col]^=1; // XOR for toggling the between 0 and 1
             
             score+=getDecimal(A,row,n-1); //Get the decimal value for each row and update the total score.
         }
         int mask=1;
         for(int col=n-1;col>0;col--) // Start from last col(LSB) in 0th row and check if flipping that column results in higher total score.
         {
             int temp = score;
             for(int row=0;row<m;row++)
             {
                 if(A[row][col]==1) // If this cell 1 then toggle makes it to zero so we have to subtract mask value from it.
                     temp-=mask;
                 else
                     temp+=mask; // zero becomes 1 then add mask to the temp score.
             }
             mask<<=1; // Left shift to consider the value to add or subtract for next LSB bit.
             score = max(score,temp); // At each toggle, check if the new score is greater than existing score.
         }
         return score;
     }
 };
