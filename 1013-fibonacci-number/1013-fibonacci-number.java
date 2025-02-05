class Solution {
    public int fib(int n) {
      int ans = 0 ;
      int f0 = 0 , f1 = 1;
       if(n < 2) {
         return n;
       }
     for(int i = 2 ; i <= n ; i++) {
         ans = f0 + f1;
         f0 = f1;
         f1 = ans;
     } 
      return ans;
    }
}