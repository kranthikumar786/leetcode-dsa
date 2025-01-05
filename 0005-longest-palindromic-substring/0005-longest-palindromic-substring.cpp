class Solution {
public:
    string expandString(string s) {
        string t = "#";
        for(char c : s) {
            t += c;
            t += '#';
        }
        return t;
    }
    string longestPalindrome(string s) {
      if(s.empty()){return "";}
      string s1 = expandString(s);
      string ans = "";
      int n = s1.size(),leftPtr ,rightPtr;
      vector<int>P(n,0);
    for (int i = 0 ; i < n ; i++) {
         leftPtr = rightPtr = i;
            while(leftPtr - 1 >= 0 && rightPtr +1 < n && s1[leftPtr-1] == s1[rightPtr+1]){
                    leftPtr--;rightPtr++;
                    P[i]++;
            }
    }
    int center = 0 , radius = 0;
    for(int i = 0 ;i < n ;i++) {
         if(P[i] > radius){
             radius = P[i];
             center = i;
         }
    }
    /*
    
    
   Test cases : 
    "" not valid TC :
    "a" -> a 
    "aa" - >aa 
    "abcde" - > "a"  

        2/2 = 1 :   
0 1 2 3 4 5 6 7 8    :     
# c # b # b # d #
0 1 0 1 2 1 0 1 0 
 centerindex = 4 , radius = 2 :
 2/2 
index / 2 = 4/2 = 2 
3
    ------------------
0 1 2 3 4 5 6 7 8    
# c # b # b # d #
1 2 1 2 3 2 1 2 1     3/2 = 1 :  
 centerPostion = 4 radius  = 3 
   startingIndex  
    */
    int start = (center - radius)/2;
     ans = s.substr(start , radius);
     
      // returing first longest palidromic substring : 
      /*
        babad : 
        1. bab 
         2  aba 
           here we are returing first only , but if we want to ahve last one simply use  if(P[i] >= radius){

      */
     return ans;
    }

/*
# b # a # b # a # b #     10-5/2 =  2 
1 2 1 4 1 10 1 2 1 2 1  

0 0 0 0 0 0 0 0 0 0 0
      2    

*/
//       string t = expandString(s);
//       int n = t.size();
//      vector<int>palindromeRadius(n,0);

//      int currentCenterIndexOfPalindrome = 0 , rightBoundaryofCurrentPalindrome = 0;

//    for(int currentIndex = 0 ; currentIndex < n ;currentIndex++) {
//       int mirror = 2 * currentCenterIndexOfPalindrome - currentIndex;  // 2 * 0  - 0 | 2 * 
//       if(currentIndex < rightBoundaryofCurrentPalindrome){
//         palindromeRadius[currentIndex] = min(rightBoundaryofCurrentPalindrome - currentIndex, palindromeRadius[mirror]);
//       }
//               // rightside < n && leftside >= 0 && check for palindrome 
//        while(currentIndex + palindromeRadius[currentIndex] + 1 < n &&  currentIndex - palindromeRadius[currentIndex] -1 >= 0 &&  t[currentIndex + palindromeRadius[currentIndex] +1] == t[currentIndex - palindromeRadius[currentIndex] -1] ){
//           palindromeRadius[currentIndex]++;       // radius increasing for current       
//        } 
//  // Update center and right since we are mvoing from left to right 
//   // if the palindrome extends beyond the currrent righmost boundary 

//       if( currentIndex + palindromeRadius[currentIndex] > rightBoundaryofCurrentPalindrome) {
//          currentCenterIndexOfPalindrome = currentIndex ;
//          rightBoundaryofCurrentPalindrome = currentIndex + palindromeRadius[currentIndex] ;
//       }
//    }

//     int longestRadius = 0 , longestCenter = 0;
//      for(int i = 0; i < n ; i++) {
//            if(palindromeRadius[i] > longestRadius) {
//              longestRadius = palindromeRadius[i];
//              longestCenter = i;
//            }
//      }
//       int start = (longestCenter - longestRadius)/ 2;
//        return s.substr(start, longestRadius);
//     }
};