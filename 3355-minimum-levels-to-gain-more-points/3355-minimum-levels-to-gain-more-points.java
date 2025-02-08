class Solution {
    public int minimumLevels(int[] possible) {
   int aliceCurrentSum = 0, n = possible.length;
        int bobSum = 0;
        for (int num : possible) {
            bobSum += (num == 0 ? -1 : 1);
        }
        for (int aliceIndex = 0; aliceIndex < n - 1; aliceIndex++) {
            aliceCurrentSum += (possible[aliceIndex] == 0 ? -1 : 1);
            bobSum -= (possible[aliceIndex] == 0 ? -1 : 1);  

            if (aliceCurrentSum > bobSum) {
                return aliceIndex + 1;             
                 }
        }
        return -1;
    }
}
  /**

         int bobSum = 0;
          for(int bobIndex = aliceIndex+1 ; bobIndex < n ; bobIndex++) {
                bobSum += (possible[bobIndex] == 0 ? -1 : 1);   
          }
     
  [0,0,1]

  [0,0,0,0,0]


       i CAN IT IS a sub array probelm rather then a DP probelm : 
        since it is following the neight approach : 
       
       Naive approach : 
        f= 0 ;
         for(int  i = 0 ; i < n ;i++) {
              alice += possible[i];
             aliceMax = Math.Max(alimMax, alice);
             int boBSum = 0;
              for(int j = i +1 ; j < n ;j++) {
                   boBSum += possible[j];
              }
             if(!f && aliceMax > boBsum) {
                f = 1 ;
                  aliceMax;
                 return i+1; 
             }
         }
     return n;
        */