/*

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.

*/

 class Solution {
 public:
     int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
     {
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
         
         int start=-1; // To store the starting index
         int n = (int)gas.size();
         int count=1; // Only one cycle is possible and if there is no valid starting point we can come out.
         int curr = 0; // Amount of gas left at a given station i
         int prev = 0; // To keep track of the cost of gas to travel from station i to i+1,so when we are at i+1 then prev is cost[i]
         int st = 0;
         
         while(count<=2)
         {
             if(st==n)
             {
                 st%=n; //To wrap around
                 count++;
             }
             if(st==start)
                 return start;
             
             if(gas[st]>=cost[st] or (curr+gas[st]-prev)>=cost[st]) // If the current gas is more or total upto this point is more
             {
                 curr = curr+gas[st]-prev;
                 prev = cost[st];
                 start = (start==-1 ? st : start);
                 if(gas[st]>curr) // At a given station, if the total gas is less than current gas then reset the total gas and also reset the start to current index
                 {
                     curr = gas[st];
                     start = st;
                 }
             }
             else
             { // Reset the start and other variables as we couldn't go further with previous starting index
                 start=-1;
                 curr=0;
                 prev=0;
             } 
             st++;
         }
         return -1;
     }
 };
