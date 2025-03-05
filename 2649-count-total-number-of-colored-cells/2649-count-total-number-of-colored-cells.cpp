class Solution {
public:
    long long coloredCells(int n) {
     
      if(n == 1) {return 1;}
      long long ans = 1;
      for(int i = 1; i < n ;i++) {
         ans += (4*i);
      }  
     return ans; 

/*
    n = 1: 
     1 : 
    
     n = 2 : 
     1 + 4 : 

      n = 3 : 

      4 + 8 +1 = 12 :
       n= 1 : 
          + 4*1 + 4*2 = 
       1 + 4 + 8 =  13 : 
  
    if(n == 1){return 1;}
    long long ans = 1;
      for(int i = 1; i < n ;i++) {
          long ans += (4*i);
          1 + 4 + 8 = 
      }

    */ 

    }
};