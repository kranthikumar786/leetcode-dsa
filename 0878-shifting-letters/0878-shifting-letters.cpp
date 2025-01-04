class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
     int n = s.size();
    long long  shift = 0 ; 
      // rightSum = 0;
    //  for(int i = 0 ; i < n ; i++) {
    //       rightSum  = (rightSum +shifts[i]) %26; 
    //  }

    // left = 0 ;
    //    3 + 5 + 9 = 17 :  a : 
    //    left = 3 :
    //        5 + 9 = 14 : 

    //     left = 8 :
    //           9    
      for(int k = n-1 ; k >= 0; k--){    
              int ch = s[k] -'a';
              shift += shifts[k];
              shift = shift%26; 
              int number = (ch + shift)%26;
             s[k] = number + 'a';   
      }  
   return  s;
    }
};
  /*

   optimazation 3: with single time  loop : 
    timeComplexity : O(n)
    spaceComplexity : O(1)

optimazation 2: with  two times loop :  find sum then traverse
    timeComplexity : O(n)
    spaceComplexity : O(1)



optimazation 1:   everychar maintains how many time has to shift in preComputedShift array then shift
    timeComplexity : O(n)
    spaceComplexity : O(n)

  optimzation on what ..? 
   for sure i have to travese the shifts so no skip or prepreocessing for it : 
      repreatively doing for every substring : ..? 
      abc
      a - > s[0] time : 
      ab - > s[1] times : 
      abc - > s[2] times : 

       at begining only let's find how many time a can be part of it : 
         a is part of all substring :  a  times : 
         b - > is part of b and bc : since i already have a count so simply  b  times =   rightSum - leftSum(a count) : 
          c - > is part of  only c  again same logic  c times = rightSum - leftSum(ab times) : 
      
     sometime like prepreocssing how many time everyd char has to change: 
  =========================================


class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
     int n = s.size();
      for(int k = 0 ; k < n; k++){   
           for(int j = 0 ; j <= k ; j++) { 
              int ch = s[j] -'a';
              long long  nu = shifts[k];
              int number = (ch + nu)%26;
             s[j] = number + 'a';   
           }
      }  
   return  s;
    }
};
  timeComplexity :  O(k * n) = 10^9 * 10^5 = 10^15 , easily TLE
  spaceComplexity : O(1)
   verdict : TLE

   tc : 
     "a"  [1] : 
    no empty string allowed :
    "aa" [1,2,3] : not allowed: 



     "a b c"
      d b c  
      i g c 
      r p  l 
       every substring of size : 
       "abc"   shifts = [3,5,9] : 
        b
        c
        dbc 
         c
         d
         e
         f
        dgc
           d
           e
           f
           g
           h
           i
           j
           k
           l
    
        s[i]   (s[i]+ sifts[i])%26; 
 */ 

  