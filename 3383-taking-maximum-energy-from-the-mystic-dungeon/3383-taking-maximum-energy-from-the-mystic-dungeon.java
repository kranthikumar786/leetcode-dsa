class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int maxEnergy = Integer.MIN_VALUE;
         int n = energy.length;
         int dp[] = new int[n];
         for(int i = n-1 ; i >= 0; i--) {
             if(i+k >= n) {
                  dp[i] = energy[i];
             } else{
                  dp[i] += (dp[i+k] + energy[i]);
             }
         }
        for(int i = 0 ; i < n ; i++) {
           maxEnergy = Math.max(maxEnergy,dp[i]);   
        } 
         
  return maxEnergy;
     /**
     Optmizaton  : Dryn RUN :
   [1,2,3,4,5,6] k = 3: 
    1     5       
      2     7   
        3     9 
           4  
              5 6 


         for(int i = 0 ; i < n ;i++) {
                int maxV = energy[i]; 
                 for(int j = i+k; j < n ; j+=k) {
                       maxV += energy[j];
                     
                 }
               maxEnergy = Math.max(maxEnergy,maxV);  
         }



  [1,2,3,4,56] , k= 3
   
[[1,2,-3,4,-5] k = 3: 
   ans : 5
     INputs: 
      -ve, +ve , and 
     co-relation b/e two inpus : 
        enry.lenth >= k always if not what to do .? 

         can fit int always : 


     [5,2,-10,-5,1], k = 3
      0 1  2   3 4
     

      for(int i = 0 ; i < n ;i++) {
              int maxV = en[i];
           for(int j = i+k ; j < n ;j+=k) {
               maxV += en[j]; 
           }
       ans = Math.max(ans,maxV);
      }
      return ans;


    0  +3 = 3 = 0
    1+ 3 = 4 : 2+1 = 3: 
    2 + 3 = 5: 
       from next onward can't take  this : 

     1+ 3 = 4: reacheable : 
     last one:

 --------------------
 [-2,-3,-1], k = 2
  0   1   2

  0 + 2 = 2 : 
  -2+-1 = -1 : 
      */   
    }
}