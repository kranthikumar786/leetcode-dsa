class Solution {
    public int climbStairs(int n) {
      if(n <= 2) {
         return n;
      }
      int distinctWays = 0 ,f0 = 1, f1 = 2;
       for(int i = 3; i <=n ;i++) {
          distinctWays = f0 + f1;
          f0 = f1 ;
          f1 = distinctWays; 
       }
       return distinctWays;
    }
}
/**
       n = 4 : 4 : 
        n = 3 :
  2 = 1+ 1 = 2: 
      p2 = steps: 
       2 = 2 :
      p1 = 1 : 

p1 =1 , p2 = 2, steps = 2 : 
     n = 3 : 
   steps =  2 +1 = 3: 
 
    p2 = 2 : 
    p1 = 2 :

  steps = 3 , p2= 2 , p1 =2 :
    n = 4 : 

   step = 2 +2 =4 : 


      1  2 :

      n = 3 :
         1 +1 + 1 =3 
         1 + 2 = 
         2 + 1  


        n = 4 : 
          1 + 1 + 1 +1  = 
          1 + 1 + 2 : 
          2 + 1 + 1 
          2 + 2 = 
          
      n = 2 : 
        
        either  1 or 2 steps : 
        n = 2 : 1 + 1  = 2 :  1 
              2  == 2 :  1         
    
            2: 
     * */ 