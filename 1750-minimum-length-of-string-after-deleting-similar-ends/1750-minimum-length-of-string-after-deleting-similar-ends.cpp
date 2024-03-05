class Solution {
public:
    int minimumLength(string s) {
 
        /*
        cabaabac 
        aba
        */
        
        int  leftPointer = 0 , rightPointer =  s.length() - 1; ;
        while ( leftPointer < rightPointer && s[leftPointer] == s[rightPointer] ) {
                  char c = s[leftPointer];
             while (leftPointer <= rightPointer && s[leftPointer] == c) {
                  leftPointer ++;
             } 
             while ( rightPointer > leftPointer && s[rightPointer] == c) {
                    rightPointer --;
             }
        }
        return rightPointer - leftPointer + 1;
    }
};
