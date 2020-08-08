/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

Note:

1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.



Our goal is to keep generating the numbers between 1 to n i.e. nth super ugly number. The series starts from 1 as given and all the prime factors of the consecutive numbers should part of given primes[] array.

We have to maintain 2 arrays.

To store the ugly numbers.
To store the indices[i] of next ugly number to be used for multiplying with the corresponding prime number in primes[i]
First of all, we get the next smallest ugly number by multiplying primes[i] and ugly[] array. Why ?? Because an ugly number's prime factors should be in the given primes[] so obviously the smallest primes[] will be the next ugly number after 1 in the ugly number sequence. Hence we go with this approach of multiplying two smaller numbers to get next ugly number.

When primes[] =** { 2,7,13,19 } **the indices[] will also be of same size and initialized with 0's. In order to get next ugly number in the sequence it should be the smallest number possible,which we can get it by multiplying smallest number from primes[] and smallest ugly number in the ugly number sub-sequence. Indices[i] stores the index of the next ugly number that should multiplied with primes[i].

When we start with primes[0] = 2, indices[0] = 0 ---> this is the index of ugly[] array. i.e ugly[indices[0]] = ugly[0]. As we multiply and take the minimum product, ugly[0] * primes[0] = 21 as ugly[0] is defaulted to 1 so the next ugly number is 2.

ugly[] = {1,2}
indices[] = { 1,0,0,0 } ---> indices[0] has index 1 from ugly number so it refers to value 2.

Next ugly number is 4 :
ugly[indices[0]] = ugly[1] * primes[0] = 2 * 2 = 4. Note that its waste of multiplying with 1 because we already multiplied and got 2 earlier..Next smallest number to multiply is 2 hence we stored the index of that in indices array in previous iteration. Once we got 4 as next ugly number, indices[] array becomes ** { 2, 0, 0 , 0 }** . It becomes 2 because when we want to multiply primes[0] with next smallest ugly number which we havent multiplied is 4 and its index is 2 in ugly array so indices[0] becomes 2. Hence everytime we use a particular number in the ugly number sequence we increment the index in indices array by 1 so that next time when we multiply we are pointing to correct ugly number.

Next ugly number is 7:
ugly[indices[0]] = ugly[2] * primes[0] = 4 * 2 = 8
ugly[indices[1]] = ugly[0] * primes[1] = 1 * 7 = 7....7 is the minimum so that is our next ugly number. If you notice here, after ugly number 4, we go straight to ugly number 1 because for the prime number 7, we havent multiplied with 1 like we did for 2 in the beginning. So from here the prime number 7's subsequence has been started from 1. As we used 1 from ugly number sub sequence for prime number 7, increment to next ugly number index to use for prime number 7. So the indices[] will look like {2,1,0,0 }.

The above process goes on until we find the nth super ugly number. I hope this makes it clear !

*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        priority_queue<long,vector<long>,greater<long>> pq;
        long ans=1;
        int count=1;
        for(auto num : primes)
            pq.push(num);
        while(count<n)
        {
            ans = pq.top();
            pq.pop();
            if(pq.empty() or ans!=pq.top())
            {
                count++;
                for(auto num:primes)
                    pq.push(num*ans);
            }
        }
        return ans;
        
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
            vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
            ugly[0]=1;
            for(int i=1; i<n; i++)
            {
                for(int j=0; j<primes.size(); j++)
                    ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
                for(int j=0; j<primes.size(); j++)
                    index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
            }
            return ugly[n-1];
    }
};
