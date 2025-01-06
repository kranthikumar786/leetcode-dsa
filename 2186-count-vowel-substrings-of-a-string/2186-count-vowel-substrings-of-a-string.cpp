class Solution {
public:
 bool isVowel(char ch) {
     return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
 }
    int countVowelSubstrings(string word) {
      int count = 0 ;
      vector<string>subs;
       int n = word.size();
    //    "aeiouu"  6 -5  : 
    //    1 
       for(int i = 0 ; i <= n-5 ; i++) {
          string sub = "";
          for(int j = i ; j < n; j++){ 
            sub += word[j];
          subs.push_back(sub);
          }
      }
   for(int i = 0 ; i < subs.size() ; i++) {
        string sub = subs[i];
        bool f = 0;
        unordered_map<char, int>fre;
        for(int j = 0 ;  j < sub.size() ; j++) {
             if(!isVowel(sub[j])){
                  f = 1;
                   break;
             }
            fre[sub[j]]++;  
       }  
    if (!f && fre['a'] > 0 && fre['e'] > 0 && fre['i'] > 0 && fre['o'] > 0 && fre['u'] > 0) {
                    count++;
    }
   }
  return count;
     /*
       generate all substring : (n*n)
        store in vecotr : 
       (n*n) : 
        then take every substring then check for con present 
  tc : O(n*n) + O(n*n) 
  sc : O(n * (n+1)/2) : 
     ---------------------------
     naive approach : 
     generate all substring :
     and check every substring if cons found then break : else count++
      TC : o(n*n*n)
      SC : O(1)

     */   
    }
};