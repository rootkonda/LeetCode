/*
You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 


Constraints:

trips.length <= 1000
trips[i].length == 3
1 <= trips[i][0] <= 100
0 <= trips[i][1] < trips[i][2] <= 1000
1 <= capacity <= 100000


*/


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        map<int,int> pick;
        map<int,int> drop;
        for(auto vec : trips)
        {
            pick[vec[1]]+=vec[0];   // sorted list of pick-up points with the total people to add to the current capacity. i.e. when two trips have same starting point then total will be more.
            drop[vec[2]]+=vec[0];  // sorted list of drop-off points with the total people to subtract from the current capacity.
        }
        int curr=0;
        map<int,int>::iterator dr = drop.begin();
        for(auto itr : pick)
        {
            while(dr->first<=itr.first) //For every pick up point we check if it is less than or equal to the drop off point. If so, then we keep subtracting the people, who should have been dropped off before this current pick-up point(itr) from the capacity thus leaving room for the current pick-up point.
            {
                curr-=dr->second;
                dr++; // After removing just goto the next drop-off point
            }
            curr+=itr.second;
            if(curr>capacity) //At any point if the curr(number of people) is more than capacity than return false;
                return false;
        }
        return true;
    }
};
