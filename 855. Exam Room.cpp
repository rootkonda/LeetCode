/*

In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)

Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.

Goal is to find a seat which is farther from any occupied seats. Keep storing the occupied seat numbers and then start finding the next seat.
*/
class ExamRoom {
public:
    int n;
    vector<int> seats;
    ExamRoom(int N) 
    {
        n = N;
    }
    
    int seat() 
    {
        if(seats.size()==0)
        {
            seats.push_back(0);
            return 0;
        }
        int dist = max(seats[0],n-1-seats[seats.size()-1]); // Find the current max distance.
        for(int i=0;i<seats.size()-1;i++)
            dist = max(dist,(seats[i+1]-seats[i])/2); // Keep checking the distance between two consecutive occupied seats, that would be the middle seat.
        if (seats[0] == dist) //Incase when first seat 0 was removed earlier then insert 0 .
        {
            seats.insert(seats.begin(), 0);
            return 0;
        }
        for(int i=0;i<seats.size()-1;i++)
        {
            int d = (seats[i+1]-seats[i])/2;
            if(d==dist)
            {
                seats.insert(seats.begin()+i+1,(seats[i+1]+seats[i])/2);// insert the new seat in between
                return seats[i+1];
            }
        }
        seats.push_back(n-1);
        return n-1;
    }
    
    void leave(int p) 
    {
        for(int i=0;i<seats.size();i++)
            if(seats[i]==p)
                seats.erase(seats.begin()+i);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);

*/
