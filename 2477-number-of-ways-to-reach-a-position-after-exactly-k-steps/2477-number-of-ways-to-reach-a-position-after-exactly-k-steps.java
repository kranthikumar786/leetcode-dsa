class Solution {
     int Mod = 1000000007;
     int dp[][];
    int find(int startPos,int endPos , int k){  
           if(k == 0 ) {
              if(startPos == endPos)
                   return 1;
           return 0;        
        }
       if(dp[startPos+2001][k] != -1){
           return dp[startPos+2001][k];
       }
       int leftStep  = find(startPos-1,endPos,k-1);
       int rightStep = find(startPos+1,endPos,k-1);
       dp[startPos+2001][k] = (leftStep + rightStep)%Mod;
     return dp[startPos+2001][k];   
    }
    public int numberOfWays(int startPos, int endPos, int k) {
        dp = new int[4001][1001];
        for(int array[] : dp){
            Arrays.fill(array,-1);
        }
        return find(startPos,endPos,k);
    }
}
/**
     
     1  2   k = 3 

     1 -> 2 -> 3 -> 2 : k = 3 :

     1->2->1->2 : k = 3 : 

     1- > 0 - > 1 - >2 : 

     if(n < startPos){
         return 0;
     }
     (n == endPos && k == 0)
          ans + 1 ;
     rec (n + 1,k-1)
     rec(n - 1,k-1)

     1 + 2 + 3 + 4 =   if (startPos > end pos || n >= startPos) return 0; 
     (startPos == endPos && k == 0)
          ans + 1 ;

  so don't modify start and end pos : 
   use  other varible to move 
   becuase if i go -- values then it is depdencult to move : 
      */