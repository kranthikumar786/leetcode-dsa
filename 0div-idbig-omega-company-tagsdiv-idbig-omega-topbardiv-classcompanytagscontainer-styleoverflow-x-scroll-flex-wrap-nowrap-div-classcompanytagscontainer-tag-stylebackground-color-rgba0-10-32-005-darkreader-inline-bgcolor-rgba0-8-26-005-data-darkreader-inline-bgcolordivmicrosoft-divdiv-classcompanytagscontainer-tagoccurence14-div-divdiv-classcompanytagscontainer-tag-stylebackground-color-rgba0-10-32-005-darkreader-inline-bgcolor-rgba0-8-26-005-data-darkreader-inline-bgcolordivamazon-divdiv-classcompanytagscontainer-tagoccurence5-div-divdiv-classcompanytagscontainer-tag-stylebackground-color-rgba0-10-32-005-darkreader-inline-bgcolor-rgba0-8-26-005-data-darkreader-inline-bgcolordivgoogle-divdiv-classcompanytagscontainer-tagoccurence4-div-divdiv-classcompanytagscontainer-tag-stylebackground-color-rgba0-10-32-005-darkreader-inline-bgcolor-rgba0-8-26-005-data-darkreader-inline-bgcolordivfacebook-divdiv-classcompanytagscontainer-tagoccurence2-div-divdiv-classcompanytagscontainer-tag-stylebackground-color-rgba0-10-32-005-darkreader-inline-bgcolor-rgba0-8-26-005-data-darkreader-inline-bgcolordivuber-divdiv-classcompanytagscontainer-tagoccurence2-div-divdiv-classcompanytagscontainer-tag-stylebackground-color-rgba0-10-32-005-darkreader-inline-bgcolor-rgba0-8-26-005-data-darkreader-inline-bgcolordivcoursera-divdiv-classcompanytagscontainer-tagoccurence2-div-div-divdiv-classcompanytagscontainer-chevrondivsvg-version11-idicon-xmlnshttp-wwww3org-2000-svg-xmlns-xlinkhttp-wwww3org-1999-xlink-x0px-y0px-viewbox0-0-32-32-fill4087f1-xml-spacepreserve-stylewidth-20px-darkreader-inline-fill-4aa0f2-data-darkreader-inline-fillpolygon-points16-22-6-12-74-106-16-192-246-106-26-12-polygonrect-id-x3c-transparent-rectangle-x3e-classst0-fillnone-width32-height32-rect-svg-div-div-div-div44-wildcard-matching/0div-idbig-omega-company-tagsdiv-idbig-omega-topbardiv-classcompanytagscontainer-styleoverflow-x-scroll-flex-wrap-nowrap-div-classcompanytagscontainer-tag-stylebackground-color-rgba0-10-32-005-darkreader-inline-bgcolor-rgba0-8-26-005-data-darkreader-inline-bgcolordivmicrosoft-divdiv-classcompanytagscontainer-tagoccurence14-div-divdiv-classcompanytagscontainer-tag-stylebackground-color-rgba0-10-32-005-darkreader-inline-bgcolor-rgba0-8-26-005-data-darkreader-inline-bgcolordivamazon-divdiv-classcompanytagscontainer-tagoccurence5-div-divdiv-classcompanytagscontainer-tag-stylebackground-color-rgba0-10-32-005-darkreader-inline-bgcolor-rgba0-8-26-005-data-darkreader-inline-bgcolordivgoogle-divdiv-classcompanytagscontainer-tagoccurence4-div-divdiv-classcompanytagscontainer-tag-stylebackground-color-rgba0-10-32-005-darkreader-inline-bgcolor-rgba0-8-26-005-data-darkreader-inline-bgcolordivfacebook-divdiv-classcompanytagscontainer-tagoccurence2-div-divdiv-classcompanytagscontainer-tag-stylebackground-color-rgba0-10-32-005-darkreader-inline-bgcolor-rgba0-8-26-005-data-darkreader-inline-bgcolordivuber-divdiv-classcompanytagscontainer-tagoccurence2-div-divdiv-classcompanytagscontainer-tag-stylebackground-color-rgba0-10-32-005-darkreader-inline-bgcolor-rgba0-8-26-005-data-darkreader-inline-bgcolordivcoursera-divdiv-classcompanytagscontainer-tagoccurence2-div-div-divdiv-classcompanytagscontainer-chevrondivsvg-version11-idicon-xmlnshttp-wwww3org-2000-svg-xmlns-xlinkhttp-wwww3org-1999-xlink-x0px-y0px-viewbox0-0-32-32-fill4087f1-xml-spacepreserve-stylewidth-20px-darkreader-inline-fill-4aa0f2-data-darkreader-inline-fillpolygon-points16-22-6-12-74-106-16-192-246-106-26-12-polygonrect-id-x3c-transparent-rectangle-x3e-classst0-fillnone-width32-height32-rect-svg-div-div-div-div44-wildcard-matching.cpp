
class Solution {
public:
/*bool isMatchHelper(int i, int j ,string &pattern, string &text,vector<vector<int>> &DP) {
	
    if(i == 0 && j == 0) {return true;}
    if (i == 0 && j> 0){return false;}
    if(j == 0 && i >0) {
        for(int k = 1 ; k <= i ;k++){
             if(pattern[k-1] != '*'){
                  return false;
             }
        }
       return true; 
    }
    if(DP[i][j] != -1) {
        return DP[i][j];
    }
    
   if( pattern[i-1] == text[j] || pattern[i-1] == '?') {
        return DP[i][j] =  isMatchHelper(i-1, j-1, pattern,text,DP);
   } 
    
   if( pattern[i-1] == '*'){
       return DP[i][j] =  (isMatchHelper(i-1,j,pattern,text,DP) || isMatchHelper(i,j-1,pattern,text,DP));
   } 
  return DP[i][j] =  false;  
}  */ 
    
    bool isMatch(string s, string p) {
        
      /*  int n = p.length();
        int  m= s.length();
      
        vector<vector<bool>>DP(n+1,vector<bool>(m+1,false));
         //return isMatchHelper(n,m,p,s,DP);  
    
        DP[0][0] =true;
      for ( int j = 1 ; j <= m; j++ ) {
            DP[0][j] = false;
      }
    
         for(int i = 1 ; i <= n ;i++) {
               bool flag = true;
             for(int k = 1 ; k <= i ;k++){
             if(p[k-1] != '*'){
                  flag = false;
                 break;
             }
         }
          DP[i][0] = flag;   
    }    
        
        
        for (int i = 1 ; i <= n ; i++) {
             for (int j = 1 ; j <= m ; j++) {
                 
                 if( p[i-1] == s[j -1] || p[i-1] == '?') {
                   DP[i][j] =  DP[i-1][j-1] ;
                } else if(p[i -1] == '*') {
                     DP[i][j] = DP[i-1][j] || DP[i][j-1];
                 }else {
                     DP[i][j] = false;
                 }
     }
} 
     
       return DP[n][m]; }
      */
       
        int r = p.size();
        int c = s.size();
        vector<bool>previousRow(c+1,false);
        vector<bool>currentRow(c+1,false);
        previousRow[0] = true;
        bool dn = true;

        for(int i=1;i<=r;i++){
            if(p[i-1]!='*')
                dn = false;
            if(dn)
                currentRow[0] = true;
            else
                currentRow[0] = false;
                
            for(int j=1;j<=c;j++){
                if(p[i-1]=='?'){
                    currentRow[j] = previousRow[j-1];continue;
                }

                if(p[i-1]=='*'){
                    currentRow[j] = previousRow[j-1] | previousRow[j] | currentRow[j-1];
                    continue;
                }

                if(p[i-1]==s[j-1])
                    currentRow[j] = previousRow[j-1];
                else
                    currentRow[j] = false;
                
            }

            previousRow = currentRow;
        }
        return previousRow[c];}
       
};

