class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
// the largest power of three within 32 bits signed interger is 3 ^ 19 = 1162261467  

//    if(n == 1){return true;}
//        if(n <= 0  || n%3 != 0) {return false;}
//        while(n > 1) {
//          if(n%3 != 0) {
//             return false;
//          }
//          n /=3;
//        }
// return true;
        
        
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