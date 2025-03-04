class Solution {
public:
    bool checkPowersOfThree(int n) {
    
    while(n > 0){
        if(n%3 == 2){
             return false;
        }
        n = n/3;
    }
    return true;
     /*
     12 :
     3^0 + 3^1 + 3^2 = 1 + 3 + 9 13 > 12 : 
          remove from left or right ...?
       3^0 : 3^1 + 3^2 = 12 == 12 : return true : 
       91 : 
       3^0 + 3^1 + 3^2 +3^3 + 3^4
        1 + 3 + 9 + 27  + 81 = 111 : 

          exclude :  1 110 :  != n : 
          exclude :  3 108 != n : 
           exclude   9 : 102 != n  : 
           eclude    27: won't get n : 
           exclude 81 won't get n : 
    try with : 
           ecluding 1 3 : 107 : 
        first : get the  power of value till >= n : 
            21 : 
            22 : 
            41
        76 : 
     */   
    }
};