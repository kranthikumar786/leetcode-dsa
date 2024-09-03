class Solution {
public:
    string stringHash(string s, int k) {
      string ans = "";
      int left = 0 , end = s.length()-1;
      int sum = 0;
         while ( left <= end ) {  
                    sum += s[left] - 'a';
                    left++;
               if((left)%k == 0) {
                   ans += (sum%26) +'a';    
                    sum = 0;
               }
         }
        return ans; 
    }
};