/*
Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.
Constraints:

1 <= hour <= 12
0 <= minutes <= 59
Answers within 10^-5 of the actual value will be accepted as correct.

https://www.youtube.com/watch?v=tW4RYgzN6fA
The minute hand moves by minute_deg_per_min = 360° / 60 = 6° per minute.
The hour hand moves by hour_deg_per_hour = 360° / 12 = 30° per hour.
The hour hand has an additional movement of hour_deg_per_min = hour_deg_per_hour / 60 = 30° / 60 = 0.5° per minute.

Therefore we get the following movements:

hour_hand_deg = hour * hour_deg_per_hour + minutes * hour_deg_per_min = hour * 30 + minutes * 0.5
minute_hand_deg = minutes * minute_deg_per_min = minutes * 6
We need the absolute difference between those two:

diff_deg = |hour_hand_deg - minute_hand_deg| = |hour * 30 + minutes * 0.5 - minutes * 6| = |hour * 30 - minutes * 5.5|
As we can easily see when looking at a clock there are two different angles between the hands:
The minimum angle on one side is between 0° and 180°.
The maximum angle on the other side is between 180° and 360°.
We need the minimum angle. If our formular returned a number above 180° we got the maximum angle.
We can calculate the minimum angle by subtracting the maximum angle from 360°.

Time and space complexity: O(1)


*/

class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        double one_hour = 30.0;
        double one_min = 6.0;
        double diff = abs((hour+(minutes/60.0))*one_hour - (minutes*one_min));
        return (diff<=180 ? diff : 360.0-diff); 
    }
};
