class Solution {
public:

     vector<string> extractWordsFromSentence(string sentence){
           vector<string>wordList;
           string word = "";
             for(char c : sentence ) {
                  if(c != ' '){
                      word += c;
                  } else{
                     if(!word.empty()){
                         wordList.push_back(word);
                          word = "";
                     }
                  }
               }
          if(!word.empty()){
              wordList.push_back(word);
          }
          return wordList; 
   }
   int prefixSearchWordIndexWord(vector<string>wordList , string searchWord ){
            int wordListLength = wordList.size();
             int searchWordLength = searchWord.size();
                for(int sentenceIndex = 0 ;sentenceIndex < wordListLength  ; sentenceIndex++ ) {
                    string word = wordList[sentenceIndex];  
                        //if(word.length() < searchWordLength )
                          //  continue;
                           if(word.length() >= searchWordLength ) {
                            int wordIndex =  0 , searchWordIndex = 0;
                            while(wordIndex < word.size()) {
                                if(searchWord[searchWordIndex] == word[wordIndex]) {
                                        searchWordIndex++;
                                        wordIndex++;
                                    if(searchWordIndex == searchWordLength){
                                            return sentenceIndex + 1; 
                                    }    
                                } else{
                                    break; // since we are not loooking for substring so break it; 
                                }
                            }
                           }
                    }
                return -1;
   }
    int isPrefixOfWord(string sentence, string searchWord) {
       int searchWordLength = searchWord.length();
       int sentenceLength = sentence.length();
        if(searchWordLength > sentenceLength ){
             return -1;
        }
       vector<string>wordList = extractWordsFromSentence(sentence);
     return prefixSearchWordIndexWord(wordList,searchWord);  
    }
};

/*

 todo : 
     rather then creating complet wordList : word then check it at a time save space for best cases: 


 timeComplexity : O(sentenceLendth) + O(wordListLength * searchWordLength)
 spaceComplexity : O(wordListLength)  



 TC : WORST CASE : 

 "bure burz burzz burzzz"  "burg"  : -1 :   not found with worst case timecomplexity : 
 
 "bure burz burzz burg"  "burg" :  4 : found with worst case timecomplexity
 



 best case TC : 

   "burg burg burg burg" "burg"  : 1 : best case  timecomplexity 

avg case TC : 
 

  "burt burtt burg burggt burgh" "burg"  : 3 : avg case timecomplexity



 worst space complexity: 
   
   without  searchWord found :  "ii love coding"  "ba" :  creating wordList 

   with searchWordFound : "ii love coding"  "love" : creating wordList : 

duplicate :  "aaaa bbb ccc" "a" : 
sortedorder : "abcde fgh ijk" "fgh" : 
edge case :  "hi iam okay" "okay" 
base case already coverd : 
*/