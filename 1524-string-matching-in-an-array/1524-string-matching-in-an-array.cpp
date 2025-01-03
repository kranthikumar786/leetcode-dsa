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
              string lWord = words[lWordIndex];
             for(int rWordIndex = 0 ; rWordIndex < wordsLength; rWordIndex++ ){
                   if(rWordIndex != lWordIndex && lWord.length() <= words[rWordIndex].length()){
                         //cout<<words[rWordIndex]<<lWord<<"\n";
                         if(isSubString(words[rWordIndex],lWord)){
                          //   cout<<lWord<<" "<<lWordIndex<<" "<<rWordIndex<<"\n";
                            ans.push_back(lWord);
                             break;
                         }
                   }
             }  
        }
     return ans;
    }
};