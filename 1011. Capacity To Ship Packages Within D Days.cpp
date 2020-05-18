/*
A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

1. Find the minimum capacity and maximum capacity, which are possible.
2. Total weight will be the maximum capacity.
3. Maximum of Largest weight in the list of weights and sum/D will be capacity required for each day.
4. Do the binary search with low as minimum capacity and high as maximum capacity.
5. For each mid invoke the isShipPossible method to see if we can accomodate all the weights within D days.
6. If it accomodates then go left or go right. Repeat this until we reach a point where we are left with minimum capacity. 

*/
class Solution {
public:
    bool isShipmentPossible(vector<int>& weights,int capacity,int D)
    {
        int days=1;
        int curr_day_wgt=0;
        
        for(auto w : weights)
        {
            curr_day_wgt+=w;
            if(curr_day_wgt>capacity)
            {
                days++;
                curr_day_wgt=w;
            }
        }
        if(days<=D)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int D) 
    {
        int min_capacity=INT_MIN;
        int max_capacity;
        int sum=0;
        for(auto w : weights)
        {
            sum+=w;
            min_capacity = max(min_capacity,w);
        }
        max_capacity = sum;
        min_capacity = max(min_capacity,sum/D);
        int low = min_capacity;
        int high = max_capacity;
        int ans = low;
        while(low<=high)
        {
            int mid = low+((high-low)>>1);
            if(isShipmentPossible(weights,mid,D))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};
