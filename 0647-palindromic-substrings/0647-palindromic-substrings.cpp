class Solution {
public:
    int countSubstrings(string A) {
      int ans = 0 ; int n = A.length();
   for(int i = 0 ; i < n ; i++) {
          ans += 1;
          int left = i-1,right = i+1;
          while(left >= 0 && right < n) {
              if(A[left] != A[right]) {
                  break;
              }    
              left--;
              right++;
              ans +=1;
          }
           left = i , right = i+1;
           while(left >= 0 && right < n) {
                 if(A[left] != A[right]) {
                  break;
              }    
              left--;
              right++;
              ans +=1;
           }
   }
  return ans; 
    }

};
