class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
       int searchWordLength = searchWord.length();
       int sentenceLength = sentence.length();
        if(searchWordLength > sentenceLength ){
             return -1;
        }
       vector<string>wordList ;
       string word = "";
     for( char c : sentence ) {
         if(c != ' '){
             word += c;
         } else {
            if(!word.empty()){
            wordList.push_back(word);
             word = "";}
         }
     }
     if(!word.empty()){
        wordList.push_back(word);
     }     
       int wordListLength = wordList.size();
    for(int sentenceIndex = 0 ;sentenceIndex < wordListLength  ; sentenceIndex++ ) {
           string word = wordList[sentenceIndex];  
            if(word.length() < searchWordLength )
                   continue;
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
       return -1; 
    }
};