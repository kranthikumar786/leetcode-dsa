class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
      int ans = 0 ;
        for(int i = 0 ; s[i] ; i++) {
             int zc = 0, oc = 0;
             for(int j = i ; s[j]; j++) {
                   if(s[j] == '0') {
                       zc++;
                   } else {oc++;}
                 
                   if(zc <= k || oc <= k) {
                       ans++;
                   }
             }
        }
        return ans;
    }
};