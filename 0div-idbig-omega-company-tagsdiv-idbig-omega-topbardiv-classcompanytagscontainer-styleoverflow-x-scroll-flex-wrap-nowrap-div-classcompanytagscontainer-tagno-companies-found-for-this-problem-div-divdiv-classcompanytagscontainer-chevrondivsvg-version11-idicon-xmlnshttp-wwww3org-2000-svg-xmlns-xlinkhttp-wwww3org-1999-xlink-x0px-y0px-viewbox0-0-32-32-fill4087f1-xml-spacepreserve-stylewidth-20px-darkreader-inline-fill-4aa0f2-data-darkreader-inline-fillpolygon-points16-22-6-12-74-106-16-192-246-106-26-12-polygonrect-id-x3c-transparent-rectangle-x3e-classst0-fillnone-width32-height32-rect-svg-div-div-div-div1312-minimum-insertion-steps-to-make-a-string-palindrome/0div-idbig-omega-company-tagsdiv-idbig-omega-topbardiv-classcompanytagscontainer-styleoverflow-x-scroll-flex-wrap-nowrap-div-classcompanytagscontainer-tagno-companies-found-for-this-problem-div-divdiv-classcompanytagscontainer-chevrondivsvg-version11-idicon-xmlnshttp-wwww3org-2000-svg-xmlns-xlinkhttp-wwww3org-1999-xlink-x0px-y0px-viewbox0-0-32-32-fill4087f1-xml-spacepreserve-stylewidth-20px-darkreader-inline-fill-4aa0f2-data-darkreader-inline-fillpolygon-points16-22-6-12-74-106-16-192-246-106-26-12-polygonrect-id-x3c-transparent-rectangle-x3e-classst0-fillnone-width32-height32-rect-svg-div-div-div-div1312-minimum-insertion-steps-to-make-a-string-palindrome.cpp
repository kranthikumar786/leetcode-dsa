class Solution {
public:
/*int palindrom(int left , int right, string& s , vector<vector<int>>&DP) {
     if(right <= left) { return 0;}
     if(DP[left][right] != -1) { return DP[left][right];}
     if(s[left] == s[right]) {
         return DP[left][right] =  palindrom(left + 1 , right -1 ,s , DP ); 
     }

 
    return DP[left][right] =  min (palindrom(left ,right - 1 ,s, DP) + 1 , palindrom(left + 1 ,right , s, DP) + 1);
    
    
    
}

   /*if(s[left] == s[right-1]) {
         return  palindrom(left ,right - 1 ,s) + 1;
  }
    if(s[left + 1 ] == s[right]) {
         return palindrom(left + 1 ,right , s) + 1 ; 
    }
return palindrom(left + 1 , right -1 ,s)+2;

}*/
    int minInsertions(string s) {
  
       int n = s.length();
       vector<vector<int>>DP(n+1, vector<int>(n+1 , 0));
       // return palindrom(0, n-1,s,DP);
    
        
        for (int len = 2; len <= n; ++len) {
        for (int left = 0; left <= n - len; ++left) {
            int right = left + len - 1;

            if (s[left] == s[right]) {
                DP[left][right] = DP[left + 1][right - 1];
            } else {
                DP[left][right] = min(DP[left][right - 1] + 1, DP[left + 1][right] + 1);
            }
        }
            
    }
        return DP[0][n - 1];

    
    }
};



