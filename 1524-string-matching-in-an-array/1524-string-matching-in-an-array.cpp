class Solution {
public:
bool isSubString(string text , string pattern){
       int textLength = text.size(), patternLength = pattern.size();
       int textPtr = 0 , patternPtr = 0;
      for(; textPtr <= textLength-patternLength ;textPtr++){
         patternPtr = 0;
         for(;patternPtr <patternLength ; patternPtr++){
              if(text[textPtr+patternPtr] != pattern[patternPtr]){
                  break;
              }
         }
          if(patternPtr == patternLength ){return 1;}
      }
     return (textPtr == textLength && patternPtr == patternLength);
    }
    vector<string> stringMatching(vector<string>& words) {
       vector<string>ans;
       int wordsLength = words.size();
        for(int lWordIndex = 0 ;lWordIndex < wordsLength  ; lWordIndex++) {
             for(int rWordIndex = 0 ; rWordIndex < wordsLength; rWordIndex++ ){
                   if(rWordIndex != lWordIndex && words[lWordIndex].length() <= words[rWordIndex].length()){  // avoid to match substring if defintely not found and self match scenarioes
                         //cout<<words[rWordIndex]<<lWord<<"\n";
                         if(isSubString(words[rWordIndex],words[lWordIndex])){
                          //   cout<<lWord<<" "<<lWordIndex<<" "<<rWordIndex<<"\n";
                            ans.push_back(words[lWordIndex]);
                             break; // duplicates are not allowed push only once substring found
                         }
                   }
             }  
        }
     return ans;
    }
};


/*
 timeComplexity : O(wordsLength * wordsLength * maxWordSize * maxWordSize) : 100 * 100 * 30 * 30 = 10^4 * 10^2 ~ 10^6 : works without TLE :
spaceComplexity : O(1) for lWord 

------------------------------------
Input : ["as","as","as","as","as"] :
Invalid Test case  : expected variables words[0]:'as' and words[1]:'as' to have different values
-------------------------------------------------------
Input : ["as","aas","bas","cas","das"] : 
A/O :    ["as"]
E/O : ["as"]



*/