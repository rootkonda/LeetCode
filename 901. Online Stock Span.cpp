/*** Written in Java ***/

class StockSpanner {
    
    /*
        We should have a stack of a pair of (current  price, maximum number of consecutive days)
        Since we don't have an access to the indicies.
    */
    Stack<int[]> s;
    
    public StockSpanner() {
        s = new Stack<>();
    }
    
   /*
   Let's trace the algorithm together on [100, 80, 60, 70, 60, 75, 85]
   1. calling StockSpanner.next(100) should result in first element in our stack will be (100, 1) (s.size() == 1)
   2. calling StockSpanner.next(80) should result in second element in our stack will be (80, 1) (s.size() == 2)
   3. calling StockSpanner.next(60) should result in third element in our stack will be (60, 1) (s.size() == 3)
   4. Now on calling StockSpanner.next(70) we should add span of (60) + 1 {the current day}
   and remove it from stack (70, 2) (s.size() == 3)
   5. Now on calling StockSpanner.next(60) result in fourth element in our stack will be (60, 1) (s.size() == 4)
   6. Now on calling StockSpanner.next(75) we should add span of (60) and (70) + 1 {the current day}
   and remove it from stack : (75, 4) (s.size() == 3)
   7. Now on calling StockSpanner.next(85) we should add span of (75) and (80) + 1 {the current day}
   and remove it from stack : (85, 6) (s.size() == 2)
   */
    
    public int next(int price) {
        int span = 1;
        while (!s.isEmpty() && price >= s.peek()[0]) { // If the current price is greater than stack peek.
            span += s.peek()[1];
            s.pop();
        }
        s.push(new int[]{price, span});
        return span;
    }
}


