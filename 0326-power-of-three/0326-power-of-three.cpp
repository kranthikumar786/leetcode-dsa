class Solution {
public:
    bool isPowerOfThree(int n) {
   if(n == 1){return true;}
       if(n <= 0  || n%3 != 0) {return false;}
       while(n > 1) {
         if(n%3 != 0) {
            return false;
         }
         n /=3;
       }
return true;
        
        
        /*
        100 :
        011 : == 0 : 
         2 power of value : 

        1000 : 
        0111 : 

         0;

         111 : 
         110:
         110 : 

        */
    }
};