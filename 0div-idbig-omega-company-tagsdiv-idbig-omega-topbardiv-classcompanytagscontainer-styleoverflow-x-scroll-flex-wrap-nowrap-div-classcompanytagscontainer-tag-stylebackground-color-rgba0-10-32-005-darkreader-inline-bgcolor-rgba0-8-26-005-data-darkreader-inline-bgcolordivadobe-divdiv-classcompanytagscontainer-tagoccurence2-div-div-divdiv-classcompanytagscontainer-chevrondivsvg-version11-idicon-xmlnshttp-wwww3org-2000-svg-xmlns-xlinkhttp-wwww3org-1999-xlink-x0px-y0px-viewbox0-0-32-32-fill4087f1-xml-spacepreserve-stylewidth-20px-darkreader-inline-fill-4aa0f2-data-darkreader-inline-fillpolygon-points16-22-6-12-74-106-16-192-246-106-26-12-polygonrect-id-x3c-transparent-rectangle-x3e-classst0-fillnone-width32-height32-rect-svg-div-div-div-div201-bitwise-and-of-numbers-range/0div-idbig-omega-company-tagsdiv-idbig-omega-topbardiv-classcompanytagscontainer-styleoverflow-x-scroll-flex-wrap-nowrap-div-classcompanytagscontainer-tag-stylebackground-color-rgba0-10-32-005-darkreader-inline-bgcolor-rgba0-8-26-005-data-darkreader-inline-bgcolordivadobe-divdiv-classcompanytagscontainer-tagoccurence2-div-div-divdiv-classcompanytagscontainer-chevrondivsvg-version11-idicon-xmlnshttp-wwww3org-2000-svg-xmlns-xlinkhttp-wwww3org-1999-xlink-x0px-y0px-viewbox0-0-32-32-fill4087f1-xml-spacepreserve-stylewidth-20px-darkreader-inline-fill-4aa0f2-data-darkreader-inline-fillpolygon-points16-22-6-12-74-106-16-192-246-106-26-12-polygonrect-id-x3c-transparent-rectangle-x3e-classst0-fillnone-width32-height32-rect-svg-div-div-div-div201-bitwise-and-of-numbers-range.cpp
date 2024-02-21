class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      if( left == right ){
          return left;}
       bitset<32>b1(left),b2(right),b3(0);  
        
      for(int i = 31 ; i >= 0 ; i--) {
           if(b1[i] == b2[i]) 
                b3[i] = b1[i];
           else break; 
      }
      return  b3.to_ulong();  
        
        /*int ans = left;
         if( left == right )  {
             return left;}
        
       for ( int lefti = left +1 ; left<= right; lefti++ ) {
             ans ^= lefti;
       } 
      return ans;  
    }/*
    
     /* 
    Even And Odd Numbers 
    
    101
    110
    111
    
    if even even is their in that range rightmost always will be 0 :
     right-1th bit = >  check even or odd : 
        
    
    
     = > 100 => 4 
    
    
    check no.of bits = > if even then it become 1 that pariculat bit .
    
                     => if odd then it becomes 0 in that paricular bit;
                        
                        
    
    */
    }
}; 
    
    