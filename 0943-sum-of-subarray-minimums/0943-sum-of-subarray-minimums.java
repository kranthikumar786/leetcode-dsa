class Solution {
    public int sumSubarrayMins(int[] arr) {
    int n = arr.length;
    long  sum  = 0;
    int mod = 1_000_000_007;
   for(int i = 0 ; i < n ;i++) {
       int minValue = arr[i] ;
       for(int j = i ; j < n ; j++) {
             minValue = Math.min(minValue,arr[j]);
             sum = (sum +minValue)%mod;
       }
   }
    /**
     3 1 2 4 :
      3 =>3
      3 1 =>1
      3 1 2 => 1 : 
      3 1 2 4 = > 1: 
      1 = >1 :
      1 2 = > 1: 
      1 2 4 => 1: 
      2 = >2 :
       2, 4 => 2: 
       4 = > 4: 

     */
   return (int)sum;
    }
}