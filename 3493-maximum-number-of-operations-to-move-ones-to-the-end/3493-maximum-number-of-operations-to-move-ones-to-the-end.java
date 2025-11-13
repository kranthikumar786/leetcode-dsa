class Solution {
    public int maxOperations(String s) {
        int ones = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1')
                ones++;
            else if (i > 0 && s.charAt(i - 1) == '1')
                res += ones;
        }
        return res;
    }
}
     /**
      BruteForce : 
       hold an i  till it reached the 1 then update thier with 1 and cur index
          value with 0 that it: 
          Tc : O(n^2):
          SC : O(1):

 1 - >1 
 0- -1: 
   1 -1 -1 1 1 -1 1 : 
p  1  0 -1 0 1 0  1 : 


  0  0  0  1  1  1 
  -1 -2 -3 -2 -1 0 

  1 0  1  0  1 0 
  1 0  1  0  1 0 : 

  1 0 0  1  1  0 1 
  1 0 -1 0  -1 1 -1

 "1 0 0 1 1 0 1 " : 
        i



 cntZeroSoFar = 2;
 cntOneSoFar  = 1 ;

 ans += cntOneSoFar; 
 */

