class Solution {
public:
 vector<string>matchingWords;
     vector<string> stringMatching(vector<string>& words) {
    vector<string>matchingWords;
    TrieNode* root = new TrieNode(); 
    for(auto word : words) {
        for(int startIndex = 0 ;startIndex < word.size() ; startIndex++ ) {
            insertWord(root,word.substr(startIndex));
        }
    }
  for(auto word : words) {
     if(isSubstring(root, word)){
         matchingWords.push_back(word);
     }
  }
     return matchingWords;
    }
    class TrieNode{
        public : 
        int frequncy ;
        unordered_map<char,TrieNode*>childNodes;
    };
 void insertWord(TrieNode* root , string word){
      TrieNode* currentNode = root;
      for(char c : word) {
        if(currentNode -> childNodes.find(c) != currentNode-> childNodes.end()) {
                 currentNode = currentNode->childNodes[c];
                 currentNode->frequncy++;
        } else{
             TrieNode * newNode = new TrieNode();
             newNode->frequncy = 1;
              currentNode->childNodes[c] = newNode;
              currentNode = newNode;
        }
      }
 }
 bool isSubstring(TrieNode* root , string word) {
    TrieNode* currentNode = root ;

    for(char c : word) {
          currentNode = currentNode->childNodes[c];
    }
    return currentNode->frequncy > 1;
 }
};


/*




================================================
class Solution {
public:
/*
vector<int>computeLPS(string pattern){
      int patternLength = pattern.size();
      int startingIndexWithLengthRef = 0 , movingIndex = 1;
     vector<int>LPS(patternLength,0);
         while(movingIndex < patternLength) {
            if(pattern[movingIndex] == pattern[startingIndexWithLengthRef]){
            LPS[movingIndex++] = ++startingIndexWithLengthRef;
            } else if(startingIndexWithLengthRef){
                startingIndexWithLengthRef = LPS[startingIndexWithLengthRef-1];
            }else{
                movingIndex++;
            }
         }
     return LPS;
}
 bool KMPSearch(string text ,string pattern, vector<int>LPS) {
        int textPtr = 0 ,textLength = text.size();
        int  patternPtr = 0 , patternLength = pattern.size();
           while(textPtr < textLength) {
                if(text[textPtr] == pattern[patternPtr]) {
                     textPtr++; 
                     patternPtr++;
                      if(patternPtr == patternLength) { return 1;}
                } else {
                      if(patternPtr){
                       patternPtr = LPS[patternPtr-1];}
                     else{ 
                         textPtr++;
                     }
                }
           }
     return 0;
 }
    vector<string> stringMatching(vector<string>& words) {
       vector<string>ans;
       int wordsLength = words.size();
        for(int lWordIndex = 0 ;lWordIndex < wordsLength  ; lWordIndex++) {
             for(int rWordIndex = 0 ; rWordIndex < wordsLength; rWordIndex++ ){
                   if(rWordIndex != lWordIndex && words[lWordIndex].length() <= words[rWordIndex].length()){  // avoid to match substring if defintely not found and self match scenarioes
                         vector<int>computedLPS = computeLPS(words[lWordIndex]);
                           if(KMPSearch(words[rWordIndex],words[lWordIndex],computedLPS)){
                              ans.push_back(words[lWordIndex]);
                             break; 
                           }
                         // if(isSubString(words[rWordIndex],words[lWordIndex])){
                         //   ans.push_back(words[lWordIndex]);
                           //  break; // duplicates are not allowed push only once substring found
                         }
                   }
             }  
        
     return ans;
    }
};
*/
/*
====================================================================
KMP approach :
timeComplexity : O(wordsLength * wordsLength + maxWordSize + maxWordSize) 
spaceComplexity: O(maxWordSize) 
=====================================================================================================
 BruteForce approach :
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