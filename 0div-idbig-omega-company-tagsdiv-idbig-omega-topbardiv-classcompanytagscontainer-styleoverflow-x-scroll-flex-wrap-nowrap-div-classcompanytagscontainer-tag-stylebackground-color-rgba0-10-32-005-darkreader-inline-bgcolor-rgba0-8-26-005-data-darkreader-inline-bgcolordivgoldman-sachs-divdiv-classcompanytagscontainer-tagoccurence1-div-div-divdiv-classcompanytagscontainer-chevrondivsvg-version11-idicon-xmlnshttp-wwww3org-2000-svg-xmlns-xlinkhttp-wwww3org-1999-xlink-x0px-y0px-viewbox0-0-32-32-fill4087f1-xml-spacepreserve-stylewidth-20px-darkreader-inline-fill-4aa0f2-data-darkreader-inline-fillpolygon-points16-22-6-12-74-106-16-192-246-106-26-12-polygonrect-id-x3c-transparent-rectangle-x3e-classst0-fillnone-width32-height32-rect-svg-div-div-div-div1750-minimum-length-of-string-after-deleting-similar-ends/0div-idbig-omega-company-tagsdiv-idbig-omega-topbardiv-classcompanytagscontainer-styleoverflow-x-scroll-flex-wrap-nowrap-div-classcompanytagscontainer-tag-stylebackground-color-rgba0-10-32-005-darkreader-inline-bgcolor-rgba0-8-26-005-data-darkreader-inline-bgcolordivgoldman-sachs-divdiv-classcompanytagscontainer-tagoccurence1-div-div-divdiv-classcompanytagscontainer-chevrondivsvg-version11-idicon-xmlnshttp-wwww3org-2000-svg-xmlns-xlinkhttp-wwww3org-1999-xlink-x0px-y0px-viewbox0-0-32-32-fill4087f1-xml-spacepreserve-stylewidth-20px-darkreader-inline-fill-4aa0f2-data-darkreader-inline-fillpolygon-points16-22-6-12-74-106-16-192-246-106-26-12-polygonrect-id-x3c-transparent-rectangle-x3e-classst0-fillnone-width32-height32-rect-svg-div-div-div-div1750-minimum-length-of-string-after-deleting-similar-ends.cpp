class Solution {
public:
    int minimumLength(string s) {
 
        /*
        cabaabac 
        aba
        */
        int N = s.length() - 1;
        int  leftPointer = 0 , rightPointer = N ;
        int leftSPointer = 0 , rightSPointer = N;
        while ( leftPointer < rightPointer) {
        
               if(s[leftPointer] == s[rightPointer]) {
                
                   leftSPointer = leftPointer ;
                   rightSPointer = rightPointer;
                   
                   while ( leftPointer < rightPointer && s[leftPointer] == s[rightPointer]) {
                           leftPointer++;
                   }
                  
                   while ( rightSPointer >leftSPointer &&  s[leftSPointer] == s[rightSPointer]) {
                          rightSPointer--;
                   }
                   rightPointer =  rightSPointer;
               } else {
                  return rightPointer - leftPointer + 1  ;
               }
        }
        return rightPointer < leftPointer  ?  0 :rightPointer - leftPointer + 1 ;
       
    }
};