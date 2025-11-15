class Solution {
    public int sumSubarrayMins(int[] arr) {
    int n = arr.length;
    long  sum  = 0;
    int mod = 1_000_000_007;
    int leftC[] = new int[n];
    int rightC[] = new int[n];
    Stack<Integer> st = new Stack<>();
    for(int i = 0 ; i < n ; i++) {
           while(!st.isEmpty() && arr[st.peek()] > arr[i]) {
                 st.pop();
           }
           int dist = st.isEmpty() ? i+1 :i-st.peek();
           leftC[i] = dist;
           st.push(i);  
    }
    st.clear();

  for(int i = n-1; i >= 0 ;i--) {
          while(!st.isEmpty() && arr[st.peek()] >= arr[i]) {
                st.pop();
          }
          int dist = st.isEmpty() ? (n-i) : st.peek()-i;
          rightC[i] = dist;
          st.push(i); 
  } 
  for(int  i = 0 ; i < n ;i++) {
       long contrib = ((long) arr[i] * (long) leftC[i] * (long) rightC[i]) % mod;
            sum = (sum + contrib) % mod;
  } 
    /**

    for(int i = 0 ; i < n ;i++) {
       int minValue = arr[i] ;
       for(int j = i ; j < n ; j++) {
             minValue = Math.min(minValue,arr[j]);
             sum = (sum +minValue)%mod;
       }
   }
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