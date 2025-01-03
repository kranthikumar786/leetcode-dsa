class Solution {
public:
vector<int> buildLPS(string pattern) {
    int patternLength = pattern.size();
    vector<int>LPS(patternLength,0);
     int startingPtrWithLengthRef = 0 , movingIndex = 1;
       while(movingIndex < patternLength){
           if(pattern[movingIndex] == pattern[startingPtrWithLengthRef]) {
               LPS[movingIndex++] =++startingPtrWithLengthRef;
           } else if(startingPtrWithLengthRef){
             startingPtrWithLengthRef = LPS[startingPtrWithLengthRef-1];
           } else{
            movingIndex++;
           }
       }
     return LPS;
}

bool KMPSearch(string text , string pattern , vector<int>LPS) {
      int textLength = text.size() , patternLength = pattern.size();
      int textPtr = 0 ,patternPtr = 0;
         while(textPtr < textLength ) {
          if(text[textPtr] == pattern[patternPtr]){
              patternPtr++;
              textPtr++;
               if(patternPtr == patternLength){return 1;}
          } else {
               if(patternPtr){
                 patternPtr = LPS[patternPtr-1]; // this is max subString you have already reached so  no need to compare for same : simply start from this index
               }else{
                textPtr++;}
          }
         }
    return 0;
}
    int repeatedStringMatch(string a, string b) {
       int bLength = b.size() , aLength = a.size();
        string repeatString = "";
        vector<int>ComputedLPS = buildLPS(b); 
       for(int repeat = 1; repeat <= bLength / aLength + 2 ; repeat++){
            repeatString += a;
             if(repeatString.length() >= bLength && KMPSearch(repeatString, b,ComputedLPS)){
                 return repeat;
             }
       }
       return -1;
    }
    };  
/*

Optimization ..? 
repeat can;t be optimized . only isSubstring can be optimzed : 



bool isSubstring(string text , string pattern) {
    int patternLength = pattern.size();
      string concateS = pattern + '$' + text;
      int concateSLength = concateS.size();
      int textPtr = patternLength + 1 , patternPtr = 0;
        // this approach works only if substring start with same as string , but if it substring start in middle of sting then it won't works
       
       while(textPtr < concateSLength ){
            if(concateS[textPtr] == concateS[patternPtr]) {
                  patternPtr++;
                  if(concateS[patternPtr] == '$'){
                      return 1; // foundmatch : 
                  }
            }
            else {
                patternPtr = 0;
            }
            textPtr++;
       }
       return 0;
}

=========================================================================

class Solution {
public:
bool isSubstring(string text , string pattern) {
    int textLength = text.size() , patternLength = pattern.size();
    int textPtr = 0,patternPtr = 0;
  for( ;textPtr <= textLength-patternLength ; textPtr++){
             patternPtr = 0;
         for( ; patternPtr < patternLength ;  patternPtr++ ){
              if(text[textPtr + patternPtr] != pattern[patternPtr] ){
                 break;
              }
         }
         if(patternPtr == patternLength){return 1;}
  }
  return (textPtr == textLength && patternPtr == patternLength );
}
    int repeatedStringMatch(string a, string b) {
       int bLength = b.size() , aLength = a.size();
        string repeatString = "";
       for(int repeat = 1; repeat < bLength * 2 ; repeat++){
            repeatString += a;
             if(repeatString.length() >= bLength && isSubstring(repeatString, b)){
                 return repeat;
             }
       }
       return -1;
    }
    };

 timeComplexity: O(bLength * 2 *bLength * aLength)  = 10^4 *10^4*10^4 *2 = 10^12*2 sO TLE is expected
 spaceComplexity : O(bLength * 2*aLength) number size in  linear space 

ex 1 : is also good
 impossible testcase : a = "a"  b ="abcd" :  -1 : 
  
   a = "ab"   b = "ababababab"  5 : 


         t   p 
  1 - > "a"  "aa" 

1- "abcd"      
       t             p
2- "a b c d a b c d"   "c d a b c d a b"
        i               j
 1 'a'
 2 'aa'
abcdabcd

    
          abcd  > cdabcdab : 
            no so repeat : 

            abcdabcd >=  cdabcdab  
              yes : 

              now check  
                b is substring of a or not : 
           
             if( substring){retrun repatedTimes;}
              else{
                  repeate same string again : 
              }
   but how you are sure that not possible : 
        a >= b  till this we can do late we can't :
 but here abcdabcd > =cdabcdab :  but  if i repeat one more time iam getting it : 
        may something like permutaion (anagram) check possible  ..?   and do repaet till 
          or 
           repeatively addin a till a size double to  b : if not dounf then say  not possible
abcdabcdabcd = > 12 size : 
cdabcdab = > 8 : 
abcdabcdabcd
        */
