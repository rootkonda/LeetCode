/**
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:

Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.

1. Check if the house# is greater or lesser than the minium or maximum heater#
2. If a house# exists between heaters, then use binary search to find the position it has to be inserted. After that get the minimum radius between house and heater.

**/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        int radius=0;
        sort(heaters.begin(),heaters.end());
        for(int house : houses)
        {
            if(house<=heaters.front())
                radius=max(radius,heaters.front()-house);
            else if(house>=heaters.back())
                radius=max(radius,house-heaters.back());
            else
            {
                int low=0;
                int high=heaters.size()-1;
                while(low<=high)
                {
                    int mid=low+(high-low)/2;
                    if(heaters[mid]==house)
                    {
                        radius=max(radius,0);
                        break;
                    }
                    else if(heaters[mid]>house)
                        high=mid-1;
                    else
                        low=mid+1;
                }
                radius=max(radius,min(heaters[low]-house,house-heaters[high]));
            }
        }
        
        return radius;
    }
};
