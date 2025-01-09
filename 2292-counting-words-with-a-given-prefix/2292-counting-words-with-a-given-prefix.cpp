class Solution {
public:
      
    int prefixCount(vector<string>& words, string pref) {
 int count = 0, n = words.size();
  for(int i = 0 ;  i < n ;i++) {
      string word = words[i];
      if(word.size() >= pref.length() && word.substr(0,pref.length()) == pref) {
           count++;
      }
  }
     return count;
    }
};


/*
 Just with below constion without consiton substr working so substr() implmented using  i = 0 ; s[i] ; i++  but not on i = 0 ; i < n ; i++
 
IF(word.substr(0,pref.length()) == pref) {
           count++;
      }
["pay","attention","practice","attend"]

"attendiiiiiiiii"

EO : 0 
AO: 0 
*/