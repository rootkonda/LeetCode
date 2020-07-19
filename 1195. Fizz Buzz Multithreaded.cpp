/*

Write a program that outputs the string representation of numbers from 1 to n, however:

If the number is divisible by 3, output "fizz".
If the number is divisible by 5, output "buzz".
If the number is divisible by both 3 and 5, output "fizzbuzz".
For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

Suppose you are given the following code:

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:

Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
Thread D will call number() which should only output the numbers.

Mutex - Mutually exclusive, holding the lock on critical region or common region until the current thread is not updated. For other threads we put a condition for wait
unique_lock - Class helps for using methods like wait and notify_all in condition_variable class as we have to pass unique_lock object to this.
condition_variable - Class used along with Mutex and unique_lock objects in order to use notify_all and wait methods. This should be same across all threads.
*/

class FizzBuzz {
private:
    int n;
    mutex m;
    condition_variable cv;
    int count=1;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) 
    {
        while(true)
        {
            unique_lock<mutex> lock(m);
            while(count<=n and (count%3!=0 or count%5==0))
                cv.wait(lock);
            if(count>n)
                return;
            printFizz();
            count++;
            cv.notify_all();    
        }
        
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) 
    {
        while(true)
        {
             unique_lock<mutex> lock(m);
            while(count<=n and (count%3==0 or count%5!=0))
                cv.wait(lock);
            if(count>n)
                return;
            printBuzz();
            count++;
            cv.notify_all();    
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) 
    {
        while(true)
        {
            unique_lock<mutex> lock(m);
            while(count<=n and (count%3!=0 or count%5!=0))
                cv.wait(lock);
            if(count>n)
                return;
            printFizzBuzz();
            count++;
            cv.notify_all();    
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) 
    {
        while(true)
        {
            unique_lock<mutex> lock(m);
            while(count<=n and (count%3==0 or count%5==0))
                cv.wait(lock);
            if(count>n)
                return;
            printNumber(count++);
            cv.notify_all();    
        }
    }
};
