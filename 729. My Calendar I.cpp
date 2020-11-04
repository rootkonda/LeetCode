/*

Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:

MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation: 
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.
 

Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].


1. Keep the intervals sorted by start time
2. Everytime we get a book request, check the end time using lower_bound. This will give us two options:
3. One option is end ==  start of previous intervals and other option is start of previous intervals > end. 
4. In both of these cases we have to go back to previous interval to find if previous interval's end time is lesser than the given start time with the exception if the iterator is at the beginning. 

*/

class MyCalendar {
public:
    map<int,int> intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) 
    {
        auto itr = intervals.lower_bound(end);
        if( itr == intervals.begin() or (--itr)->second<=start)
        {
            intervals.insert({start,end});
            return true;
        }
        return false;
    }
};
