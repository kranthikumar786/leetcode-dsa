class Solution {
public:
    int maxDepth(string s) {
     int ans = 0,openBrackets=0;;
     
      for(char c : s) {
           if( c == '(' ) {
               openBrackets++;
           }
           if(c == ')') {
               openBrackets--;
           }
          ans = max(ans,openBrackets);
      }  
       return  ans;
        
    }
};