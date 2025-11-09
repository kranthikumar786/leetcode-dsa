class Solution {
    public int countOperations(int num1, int num2) {
         int cnt = 0;
           // n1 = 2, n2 = 3:
           /**
               n1 = 2, n2 = 1 => cnt = 1:
               n1 = 1, n2 = 1 => cnt = 2:
               n1 = 0 , n2 = 1 => cnt = 0: 

            */
         while(num1 != 0 && num2 != 0){
              if(num1 >= num2) {
                num1 -= num2;
                cnt++;
              } else{
                  num2 -= num1;
                  cnt++;
              } 
         }
      return cnt;   
    }
}

