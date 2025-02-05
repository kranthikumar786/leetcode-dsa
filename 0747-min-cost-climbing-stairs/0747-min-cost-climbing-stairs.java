class Solution {
     public int rec(int index , int n , int []cost,int dp[]){
          if(index >= n) { return 0;}
          if(dp[index] != -1){return dp[index];}
        int ans1 = cost[index] + rec(index + 1, n , cost,dp);
        int ans2 = cost[index] + rec(index + 2, n , cost,dp);
         //return Math.min(ans1,ans2);  
       return dp[index] = Math.min(ans1,ans2);
     }
    public int minCostClimbingStairs(int[] cost) {
         int n = cost.length;
         int dp[] = new int[n];
         Arrays.fill(dp,-1);
  return Math.min(rec(0,n,cost,dp),rec(1,n,cost,dp));


  /*10,15,20 : 
  TC : 2^N :
  SC  :O(N):
  Veridt can be TLE :
     10 : 
      1 : 10 ,15, 20 = > 45 :
      
       2 : 10 , 20 = > 30 : 

   15 : 
    1 : 15  + 20  = 35 : 
    2 : 15 : = 15  then out out bound : return 0 : 
       if index > n  return 0 : 



*/

        /**
        
         either i can climb with step 1 or step 2 :
          finaci numbers : 
           f[n] = f[n-1] + f[n-2] : 

            definrly reach the end : 
            ans = array[n-1] : 
         
           
            rec : if size == 2 :
              if(size ==1) { return  arr[0];}

             if(size == 2) { return Math.min(arr[0],arr[1]);}

           int index = -1; 
           = Math.min(rec(index+1) , rec(index+2)) :
                      
            for(int i = 2 ; i < n ;i++) {
              ans + = Math.min(cost[i-1],cost[i-2]);
            }





                      1, 100, 1, 1,1,100,1,1,  100,1 : 
                                             1 ,1  
                                           1, 1
                                        100  ,1
                                      1, 1
                                  1  1
                            100 1
                        1  1
                     1

                

                100  
                     1  1 1 100 1 1 100 1 
                                      1
                                   1

                                 1
                             100 1
                             1      
                       1 1
                     1 1

                  100 1 : 

         */
    }
}