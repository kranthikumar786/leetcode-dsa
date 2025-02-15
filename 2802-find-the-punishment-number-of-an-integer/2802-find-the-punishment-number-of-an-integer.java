class Solution {
    boolean canPartion(int target , int curNumber) {
           if(target > curNumber  || target < 0){
              return false;
           }
            if(curNumber == target) {
                return true;
            }
         return  (canPartion(target - (curNumber%10) , curNumber/10) ||
         canPartion(target - (curNumber%100) , curNumber/100)
         ||
         canPartion(target - (curNumber%1000) , curNumber/1000));
    }
    public int punishmentNumber(int n) {
        int punishmentNumber = 0;
        for(int curNumber = 1; curNumber <= n ;curNumber++ ) {
            int squaredNumber = curNumber * curNumber; // no need of long since 10^3
            if(canPartion(curNumber,squaredNumber)){
                punishmentNumber += squaredNumber;
            }
        }        
  return punishmentNumber;
    }
}


       
       /**
        1 to 10 : 
        1 = 1 *1  = 1: 
        2 = 2*2 = 4  , 4 itself is  length 1 substring so no furhter divisions
        3 = 3 *3  = 9 , same reason : 
        4 = 4*4 = 16 = 1+6 = 7 != i :  orignalvalue != sumofSquarevalue
        5 = 5 *5 = 25 = 2 + 5 = 7  != i : 
        6 = 6 *6 = 36 = 9 != 6 not checking strobogrammatic  
                 
        7 = 7 *7 = 49 = 13 = 4 != 7 :
        8 = 8 * 8 = 64 = 10 = 1 : 
        9 = 81 = 9  9 == 9 : 
        10 = 10 *10 = 100 = 10 how can i do it ...? if i do 100%10 : 0 + 0 + 1 = 1 not with 10 ..? 
                  how ...? do i have to convert to stirng then do it ...? 
                   pleace of division mattter ..? yes. any way we always divise into n-2 + 1 for n sized substring : 
                       to_String(10)+to_String(0) = 10:  
          
             int  num = 10^3 := > 10^3 * 10^3 = 10^9 :  do i need to store long long here ..? no not required 
               int can hold values till 10^9 : 

           went incorrect here :
               it wont; do repeatively only once it will do:
                ex : 999 = 27 = 9  
            int  num = 10^3 : 
               orignal = num;
               num =* num;
               sumOfSquare = 0 ; 
              while (num){
                  sumOfSquare = (num%10);
                  num /= 10;
              }
              return  sumOfSquare;

              commutative propoerty : useful for place subsubarray or sliwing windoe techique : 
                 but here it won;t works :
                100 = 1 + (00) != 10 + (0) 
                            so incorrect : 

         1010 = 20 which is impossbile ..? 
         20 = 20 *20 = 400 = 
         101 + 0 : 101 :  

         1, 9 , 10 ,36  = 
        since this ARE FIXED ...? 
        */  