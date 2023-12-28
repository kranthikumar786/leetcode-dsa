int memo[100][27][11][100];

class Solution {
    int dfs(string &s, int i, char prev, int prev_c, int k) {
        if (k < 0) return INT_MAX;
        if (i == s.length()) return 0;

        if (memo[i][prev - 'a'][prev_c][k] != -1) return memo[i][prev - 'a'][prev_c][k];

        //keep the index
        int result = dfs(s, i + 1, s[i], s[i] == prev ? min(10, prev_c + 1) : 1, k);
        if (s[i] == prev) result += (prev_c == 1 || prev_c == 9);
        else ++result;

        // comparing with removing index
        return memo[i][prev - 'a'][prev_c][k] = min(result, dfs(s, i + 1, prev, prev_c, k - 1));
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        const int N = s.length();
        int i;
        for (i = 1; i < N; ++i) if (s[i] != s[i - 1]) break;
        if (i == N) {
            i -= k;
            return i == 100 ? 4 : i >= 10 ? 3 : i >= 2 ? 2 : i == 1 ? 1 : 0;
        }
        memset(memo, -1, sizeof(memo));
        return dfs(s, 0, '{', 1, k);
          
        
        
        
        
        
        
        
        
        /*
       
        aaabcccd , k = 2 : 
        
        a  a 
            
             a 
                b 
                   c
                      c
                         c
                            d 
            
        
          
          
         abcccd = > abc3d = > length = 5 : 
        
        
        
            
            
        a    a  
               a 
                   a XX bcccd = > abc3d =  >5 : 
        
        
        
         a aa 
             
               b
                 c
                 ccd : 
           
          a3c2d = > 5 
              
              
      ========================================       
              a  (aab) 
                    c 
                     (ccd) 
              
              
              aabccd = > a2bc2d = > 6
              
              
             ==============================
              
              
              aaabcccd : 
        
          a (aabc)
                 c
                  (cd)
        
              aabccd : a2bc2d = > 6
==================================================
                  
                  
              aaabcccd :
        
        a (aabcc) 
                c
                  (d)
            
           aabccd = > a2bc2d = > 6 
            
            
 =====================================================    
            aaabcccd :
        
        a (aabccc)
                d 
         
            aabccc = > a2bc3 = > 5 
            
  =========================================================
          
             now start with index 1 
            
            aaabcccd :
        
          (a) 
              aa = > remove 
             (bcccd)
           
              abcccd = > abc3d = > 5 
             
   ===================================================================
                  
                  aaabcccd :
        
          a
              a
          a
               b
          cccd
              
              
          aacccd =>a2c3d => 5
              
 ========================================================================
              
              
       aaabcccd :
        
        
        a
            a
        ab
            c
        ccd
         
         aabccd => a2bc2d=> 6
            
  ====================================================================
            
       aaabcccd :
        
        a
            a
       abc  
            c
       cd
            
          aabccd=> a2bc2d=>6
===========================================================================
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            example 2 :
        
        "aabbaa", k = 2
          
            
                (aa) 
        bbaa : 
        bbaa = > b2a2 = > 4
     
            
      ==================================
           "aabbaa", k = 2
            
         
                (a)   
          a     (b)
          baa  
        
           abaa = > aba2 = > 4 : 
        
    =======================
        
        "aabbaa", k = 2
        
              (a)
        ab    (b)
        aa
        abaa = > aba2 = > 4 
     ===================================
        
        "aabbaa", k = 2
        
             (a)
        
        abb  (a)
         a
         abba = > ab2a = > 4
     ==========================================

        "aabbaa", k = 2

              (a)
       abba    (a) 
        
         abba = > ab2a =  >4
    
      ============================================
        
        "aabbaa", k = 2
        
        a  
           (ab)
        baa
        abaa = > aba2 = >4 
     ================================================
        
        "aabbaa", k = 2
        
         a
             (a)   
         b    (b)
        aa
         abaa = > aba2 =  >4
     ================================================
        
        
        "aabbaa", k = 2
        
        
        a 
             (a)
        bb    (a)
        a
       abba = > ab2a = > 4
        
      ======================================
        
        
        "aabbaa", k = 2
        
        
         a 
            (a) 
        
        
        
   */         
        
        
    }
};