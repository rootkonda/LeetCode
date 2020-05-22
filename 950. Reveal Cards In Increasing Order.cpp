/*
In a deck of cards, every card has a unique integer.  You can order the deck in any order you want.

Initially, all the cards start face down (unrevealed) in one deck.

Now, you do the following steps repeatedly, until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck, put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

The first entry in the answer is considered to be the top of the deck.

Idea is to sort the elements in ascending order and fill them in alternate empty spaces as we have to make sure the card revealing should be in increasing order.
For example: Given array is [17,13,5,2,3,7,11]

After sorting - [2,3,5,7,11,13,17]
After each iteration, it will be like this: i.e. keep filling in alternate empty spaces.
a. [2, ,3, , , , ,]
b. [2, ,3, ,5, , ,]
c. [2, , 3, , 5, ,7]
d. [2, , 3, 11 , 5, ,7]
e. [2, 13 , 3, 11 , 5, ,7]
f. [2, 13 , 3, 11 , 5, 17 ,7]

*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        sort(deck.begin(),deck.end()); // Sort in ascending order
        int n = (int)deck.size();
        vector<int> ans(n,0);
        deque<int> pos; // Use double ended queue(deque) to pop from front and push back
        for(int i=1;i<n;i++)
            pos.push_back(i); // store the empty positions
        ans[0] = deck[0];
        int index = 1; // start with 2nd smallest element
        while(!pos.empty())
        {
		    //Every time we have to pop the first free space and push back and use the next free space
            if(pos.size()>1)
            {
                pos.push_back(pos.front());
                pos.pop_front();
            }
            ans[pos.front()] = deck[index++];
            pos.pop_front(); // After using a spot in answer, pop it from the queue as it wont be available for other elements.
        }
        return ans;
    }
};
