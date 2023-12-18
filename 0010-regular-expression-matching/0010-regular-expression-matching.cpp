class Solution {
public:
    
    bool isMatching(int indexi, int indexj,string &s, string &p) {
        
         if(indexi >= s.length() && indexj >= p.length()) {
               return true;
         }
         if(indexj >= p.length()){
             return false;
         }
        
        bool match =  indexi < s.length() && (s[indexi] == p[indexj] || p[indexj] == '.');
        
        if( indexj + 1 < p.length() && p[indexj + 1] == '*'){
            return (isMatching(indexi, indexj+2, s, p) || (match && isMatching(indexi + 1 , indexj,s,p)));
        }
      
        if(match) {
            return isMatching(indexi + 1 , indexj + 1,s,p);
        }            
      
                    
      return false;  
    }
    bool isMatch(string s, string p) {
     return isMatching(0,0,s,p);   
    }
};