
class Solution {
public:
bool isMatchHelper(int i, int j ,string &pattern, string &text,vector<vector<int>> &DP) {
	
    if(i < 0 && j < 0) {return true;}
    if (i < 0 && j>= 0){return false;}
    if(j < 0 && i >=0) {
        for(int k = 0 ; k <= i ;k++){
             if(pattern[k] != '*'){
                  return false;
             }
        }
       return true; 
    }
    if(DP[i][j] != -1) {
        return DP[i][j];
    }
    
   if( pattern[i] == text[j] || pattern[i] == '?') {
        return DP[i][j] =  isMatchHelper(i-1, j-1, pattern,text,DP);
   } 
    
   if( pattern[i] == '*'){
       return DP[i][j] =  (isMatchHelper(i-1,j,pattern,text,DP) || isMatchHelper(i,j-1,pattern,text,DP));
   } 
  return DP[i][j] =  false;  
}   
    
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>>DP(n,vector<int>(m,-1));
        return isMatchHelper(n-1,m-1,p,s,DP);  
    }    
};

