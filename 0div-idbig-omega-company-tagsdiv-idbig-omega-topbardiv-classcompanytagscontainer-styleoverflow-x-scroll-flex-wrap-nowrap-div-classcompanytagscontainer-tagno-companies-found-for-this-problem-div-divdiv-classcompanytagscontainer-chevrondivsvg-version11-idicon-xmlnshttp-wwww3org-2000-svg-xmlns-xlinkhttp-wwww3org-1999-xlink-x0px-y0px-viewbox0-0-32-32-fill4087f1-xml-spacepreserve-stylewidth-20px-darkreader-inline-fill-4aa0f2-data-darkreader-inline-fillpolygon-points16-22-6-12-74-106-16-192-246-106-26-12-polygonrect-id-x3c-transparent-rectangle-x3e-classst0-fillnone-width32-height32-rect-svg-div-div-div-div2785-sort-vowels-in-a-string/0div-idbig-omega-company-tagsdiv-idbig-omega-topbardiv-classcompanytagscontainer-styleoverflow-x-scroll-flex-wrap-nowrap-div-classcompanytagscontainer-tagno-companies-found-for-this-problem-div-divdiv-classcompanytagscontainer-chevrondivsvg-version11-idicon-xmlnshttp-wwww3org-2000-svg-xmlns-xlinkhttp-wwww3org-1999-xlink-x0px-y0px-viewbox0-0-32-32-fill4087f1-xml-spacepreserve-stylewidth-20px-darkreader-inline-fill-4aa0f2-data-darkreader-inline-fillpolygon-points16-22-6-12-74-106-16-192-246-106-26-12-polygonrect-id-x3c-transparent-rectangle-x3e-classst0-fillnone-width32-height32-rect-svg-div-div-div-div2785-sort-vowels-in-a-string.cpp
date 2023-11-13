class Solution {
public:
    string sortVowels(string s) {
  
       string t = "AEIOUaeiou";
        int m[123] = {} , i = 0;
        for(auto c:s){
            m[c]++;
        }
        
        for(auto c: t) {
            
             for( ; m[c] && i < s.size() ; i++){
                 if(t.find(s[i])!= string::npos) {
                     s[i] = c, m[c]--;
                 }
             }
        }
        return s;
        
    }
};