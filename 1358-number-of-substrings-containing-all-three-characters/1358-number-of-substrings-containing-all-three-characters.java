class Solution {
    public int numberOfSubstrings(String s) {
       int ans = 0 ;
       int n = s.length(); 
        int aCnt = 0 , bCnt = 0 , cCnt = 0 ;
        int l = 0 , r = 0 ;
         while(r < n ) {
             char ch = s.charAt(r);
             if(ch == 'a'){
                 aCnt++;
              } else if(ch == 'b'){
                 bCnt++;}
               else{
                cCnt++;
               }
               while(l < r && aCnt >=1  && bCnt >=1 && cCnt >=1) {
                     ans += (n-r);
                     char ch1 = s.charAt(l);
                     if(ch1 == 'a'){
                         aCnt--;
                       } else if(ch1 == 'b'){
                         bCnt--;}
                        else{
                         cCnt--;
                         }
                       l++;  
               }
              r++;    
         }
         return ans;
    }
}
/**

for(int i = 0 ; i < n ; i++) {
             int aCnt = 0 , bCnt = 0 , cCnt = 0 ;
             for(int j = i ; j < n ;j++) {
                    if(s.charAt(j) == 'a'){
                        aCnt++; 
                    }else if(s.charAt(j) == 'b'){
                        bCnt++; 
                    } else if(s.charAt(j) == 'c'){
                        cCnt++; 
                    }
                   if(aCnt >= 1 && bCnt >= 1 && cCnt >=1 ) {
                          ans++;
                   } 
             } 
       }
       return ans;
 */