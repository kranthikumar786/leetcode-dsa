class Solution {
public:
    vector<int>computeLPS(string pattern) {
          int pattrenLength = pattern.size();
            vector<int>computedLPS(pattrenLength,0);
           int startingPtrWithLenghtRef = 0 , movingIndex = 1;
            while( movingIndex < pattrenLength ) {
                   if(pattern[startingPtrWithLenghtRef] == pattern[movingIndex]) {
                          computedLPS[movingIndex++] = ++startingPtrWithLenghtRef; 
                   } else if(startingPtrWithLenghtRef){
                        startingPtrWithLenghtRef = computedLPS[startingPtrWithLenghtRef-1];
                   } else{
                    movingIndex++;
                   }
            }
           return computedLPS;  
    }
    string longestPrefix(string s) {  
       string longestHappyPrefix = "";
        vector<int>computedLps = computeLPS(s); 
        if(computedLps.back() != 0) {
            longestHappyPrefix = s.substr(0,computedLps.back()); 
        }
       return longestHappyPrefix;
    }
    };
       /*
        ex 1: 
        "l e  v e l"
        i         j
        [0,0,0,0,1] ;
         ex 2: 
        "a b a b a b"
               i    j
        [0,0,1,2,3,4] : legnth : string ..? simple take currentindex 4  to 1: of substring


           "a b b b d" : 
            i       j 
           [0,0,0,0,0] : 
  
          "a a a a"
               i j    
          [0,1,2,3] 
             if(lps.back() == 0){ return ""};

          

       
        "a a a b" 
             i  j  
        [0,1,2,0]  : end of it LPS is zero hanec no prefixshich is also suffix
 
======================================================================================
       
       
       vector<string>prefix,suffix;
         string word = "";
         int n = s.length();
         Dryrun : 
         ex 1: 
          level  : 
          l 
          le 
          lev
          leve

        for(int i = 0 ; i < n-1 ; i++){
            word += s[i];
            prefix.push_back(word);
       }
        string word2 = "";
       for(int i = n - 1; i > 0 ; i--){
           word2 = s[i] + word2;
           suffix.push_back(word2); 
       }
   int maxLength = 0;
   string ans = "";
     for(auto prefixSubString : prefix){
          for(auto suffixSubStirng : suffix) {
             if(prefixSubString == suffixSubStirng) {
                  if(maxLength < prefixSubString.length()) {
                     maxLength = prefixSubString.length();
                     ans = prefixSubString;
                  }
             }
          }
     }
     return ans;
     }
};    


===================
 worstCase TimeCoomplexity  with longest happyPrefix: 
  s= "aaaaaa" : 
     "aaaaaa"


   "abcabdc"


        level : 
          l 
        //  el
         // l = l + e
         l = e + l 
         el : 
         vel 
         evel : 

         or not realy best way : 
          else we can also do revese on each substring  of prefix
        

     =================
       1. generate all prefix and generate all sufix string:
            String prefixWord = ""
           for(char c : s){
               prefixWord += c;
               prefixWord.push_back(prefixWord);
           }

            string suffixWord = "";
for( int end = s.length()-1  ; end > = 0 ; end--){
               prefixWord += s[end];
               sufffixWords.push_back(suffixWord);
           }

       2. start travesing prefix with suffx if match then update maxLengthprefixwhichIsSuffix 
        for(auto prefixWord :prefixWords ) {
            for(auto suffixWord : sufffixWords) {
                 if(prefixWord == suffixWord){
                
                  if(prefixWord.size() > maxLength){
                     maxLength = prefixWord.size();
                      ans = prefixWord;
                  }
                 }
            }
        }
retrun ans;      
       3.  retrun  maxLengthprefixwhichIsSuffix;
     */
