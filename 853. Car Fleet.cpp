/*
N cars are going to the same destination along a one lane road.  The destination is target miles away.

Each car i has a constant speed speed[i] (in miles per hour), and initial position position[i] miles towards the target along the road.

A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.

The distance between these two cars is ignored - they are assumed to have the same position.

A car fleet is some non-empty set of cars driving at the same position and same speed.  Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.


How many car fleets will arrive at the destination?
https://leetcode.com/problems/car-fleet/discuss/139850/C%2B%2BJavaPython-Straight-Forward


1. Find the time taken to reach the target using speed,distance and time formula and store the results in a map.
2. In a map we store distances from shortest to longest, hence we negate the distance.
3. Finally count the times greater than the last time.Return answer. This means all cars with time less than a current time are in the same fleet. If there is car with higher time then it is on its own fleet

*/
class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) 
    {
        int ans=0;
        double curr=0;
        map<int,double> mp;
        for(int i=0;i<pos.size();i++)
            mp[-pos[i]] = (double)(target-pos[i])/speed[i];
        for(auto it : mp)
            if(it.second>curr)
                curr = it.second,ans++;
        return ans;
    }
};
