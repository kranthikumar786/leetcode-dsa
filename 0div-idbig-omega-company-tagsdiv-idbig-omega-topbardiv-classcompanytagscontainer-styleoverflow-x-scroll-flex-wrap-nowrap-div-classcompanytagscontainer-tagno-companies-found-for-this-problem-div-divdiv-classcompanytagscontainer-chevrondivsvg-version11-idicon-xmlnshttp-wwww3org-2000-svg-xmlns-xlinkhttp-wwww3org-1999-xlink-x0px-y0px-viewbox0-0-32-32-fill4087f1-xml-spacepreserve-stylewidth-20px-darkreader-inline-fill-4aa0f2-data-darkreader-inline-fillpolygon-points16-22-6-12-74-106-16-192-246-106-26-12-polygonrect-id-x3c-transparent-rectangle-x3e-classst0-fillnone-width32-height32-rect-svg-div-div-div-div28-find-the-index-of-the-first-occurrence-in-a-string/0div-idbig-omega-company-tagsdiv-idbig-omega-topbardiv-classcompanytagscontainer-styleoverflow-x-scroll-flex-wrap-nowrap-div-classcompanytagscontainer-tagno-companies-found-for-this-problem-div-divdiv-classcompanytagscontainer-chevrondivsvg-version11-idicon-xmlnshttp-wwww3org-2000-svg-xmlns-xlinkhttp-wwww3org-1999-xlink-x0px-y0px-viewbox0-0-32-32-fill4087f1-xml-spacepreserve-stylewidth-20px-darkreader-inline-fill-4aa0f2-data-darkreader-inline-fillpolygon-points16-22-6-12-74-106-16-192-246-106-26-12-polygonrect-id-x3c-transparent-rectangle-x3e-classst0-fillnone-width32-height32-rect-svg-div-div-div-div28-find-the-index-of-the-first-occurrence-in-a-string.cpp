class Solution {
public:
    int strStr(string haystack, string needle) {
     
      int  needleLength = needle.size();
      int  haystackLength = haystack.size();  
       for ( int index = 0 ;index <= haystackLength - needleLength;index++ ){
             int j = 0;
          for(j = 0;needle[j]; j++){
              if(needle[j] != haystack[index + j]) {
                   break;
              }
          }
         if(j == needleLength) {
             return index;
         }  
       }
        return -1;
    }
};