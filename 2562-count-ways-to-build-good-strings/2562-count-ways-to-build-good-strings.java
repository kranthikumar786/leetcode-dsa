import java.util.Arrays;

class Solution {
    int mod = 1000000007;
    int[] dp;  
    public int rec(int n, int zero, int one) {
        if (n < 0) return 0;  
        if (n == 0) return 1;
        if (dp[n] != -1) return dp[n]; 
        dp[n] = (rec(n - zero, zero, one) + rec(n - one, zero, one)) % mod;
        return dp[n];
    }
    public int countGoodStrings(int low, int high, int zero, int one) {
        dp = new int[high + 1];  
        Arrays.fill(dp, -1);  
        int ans = 0;
        for (int i = low; i <= high; i++) {
            ans = (ans + rec(i, zero, one)) % mod;
        }
        return ans;
    }
}


        /**


         time compexity : (high-low)^2 : 
         SC : O(high)
     VERDICT : Easily TLE 
        low = 2 : high = 3 : 
        zero = 1 , one = 2 : 

  observation 1 :
  one ans zeros are in given  size : 

   zero - 0 > i can add only one time in string at a time : 
   one  : 1 - > 2 : at a time min i can add two ones : 

    now iam  thinkning towards to (n-zero) + (n - one) : 
    recusrsion realation : 

       low = 2 : 
       n = 2 : 

   int rec(int n, int zeros, int ones) {
       if(zero < 0 || ones < 0){
         return 0; 
       }
       if(zeros == 0 || ones == 0){
            return 1;
       }
        ans += rec(n, n- zeros) + rec(n,n-ones);
       return ans;
   }
       for(int i = low ; i <= high ; i++) {
                ans += rec(low ,zero, one);  
         } 
   high  =  3  ,1,2: 

    3 
       3-1 : 
    2  
       2-1 : 
    1
      1-1 : 

    formed  1 string :
    now back track : 

    2  :   2-2 = : 0 : 
    fomred string : 1 : 


    back track to 3 : 

    3
     3- 2 = 1 : 
   1 
     1- -1  = 0

     fomred on3 string 1 :         
         2 : 
         2-1 :  1 
           1-1 : 0 
         */
    