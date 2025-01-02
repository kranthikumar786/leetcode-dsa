class Solution {
public:
  vector<int>computeLPS(string pattren){
    int pattrenLength = pattren.size();
    vector<int>computedLPS(pattrenLength,0);
    int startingPtrWithLengthRef = 0;
     int movingIndex = 1;
      while(movingIndex < pattrenLength) {
           if(pattren[movingIndex] == pattren[startingPtrWithLengthRef]) {
               startingPtrWithLengthRef++;
               computedLPS[movingIndex++] = startingPtrWithLengthRef; 
            } else if(startingPtrWithLengthRef > 0){
                     startingPtrWithLengthRef = computedLPS[startingPtrWithLengthRef-1];
             } else{
                 computedLPS[movingIndex++] = 0;
            }
      }
       return computedLPS;
  }
  bool kmpSearch(string text , string pattern) {
      vector<int>computedLPS = computeLPS(pattern);
      int textIndex = 0 , patternIndex = 0;
      int textLength = text.size() , patternLength = pattern.size();
          while(textIndex < textLength) {
                if(text[textIndex] == pattern[patternIndex]) {
                      textIndex++;
                      patternIndex++;
                 
                if(patternIndex == patternLength){
                     return true; }
                    }
                  else if(patternIndex > 0 ){
                    patternIndex = computedLPS[patternIndex-1]; 
                  } else{
                    textIndex++;
                  }    
          }
          return false;
  }
    bool rotateString(string s, string goal)  {
      int sLength = s.length();
      int goalLength = goal.length();
    if(sLength != goalLength) {return false;}
      string doubledString = s + s ;
       return kmpSearch(doubledString, goal);    
    }
};

/*


tc : 
 "ababa" "abcde"
   
*/






/*
        s += s;
        return s.find(goal) != -1 and s.size() / 2 == goal.size();

 /*  s- > goal 
  

   return s == goal ;
        0 - > n-1  : 
        1->n-2 : 
        etc..

        s= "abcde" g = "bcdea" : 

     simple angaram ..? not really : frequncy may not be evalution param

   ex 1 :
   s= "abcde" g = "cdeab" : 
        bcdea , cdeab 
         cdeab:   cdeab : 
     
         Bruteforce : 
         usingQueue :  abcde : 
           front() ;
           pop();
           push_back() : 
  
     if matching half but later not matching ..? 
       so get back to first place and restart for searching : 
*/
