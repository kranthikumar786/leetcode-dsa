class Solution {
public:
    bool isVowel(char c) {
         return (c =='a' || c == 'A' || c == 'E' || c == 'e' || c == 'i' || c == 'I' || c =='O' || c == 'o' || c == 'U' || c == 'u');
    }
    bool halvesAreAlike(string s) {
     int v1 = 0 , v2 = 0, n = s.length();
       for(int i = 0 ; s[i] ; i++) {
           
           if(i < n/2 && isVowel(s[i])) {
               v1++;
           }else{
               if(isVowel(s[i]))
                    v2++;
           }
       }
       return v1 == v2; 
    }
};