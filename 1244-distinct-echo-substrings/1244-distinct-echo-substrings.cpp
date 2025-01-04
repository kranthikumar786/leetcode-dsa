class Solution {
public:
    vector<int> STRSTR(string patt) {
           string con = patt;
          int conLength = con.size();
          vector<int>zFun(conLength,0);
            int leftPtr = 0 ,rightPtr = 0;
            for(int curPtr = 1 ; curPtr < conLength ; curPtr++) {
            if(curPtr > rightPtr) {
                  rightPtr = leftPtr = curPtr;
                   while(rightPtr < conLength && con[rightPtr] == con[rightPtr-leftPtr]){
                    rightPtr++;
                   }
                   zFun[curPtr] = rightPtr -leftPtr ;
                   rightPtr--;
            } else{

               int index = curPtr - leftPtr;
                 if(zFun[index] < rightPtr-curPtr+1) {
                      zFun[curPtr] = zFun[index];
                 }
                 else{
                    leftPtr = curPtr;
                    while(rightPtr < conLength && con[rightPtr] == con[rightPtr-leftPtr]){
                    rightPtr++;
                   }
                   zFun[curPtr] = rightPtr -leftPtr ;
                   rightPtr--;
                 }
            }
        }
    return zFun;
   }
    int distinctEchoSubstrings(string text) {
         int count = 0 ;
          int textSize = text.size() ; 
          //int subStringSize = (textSize-1)/2;
        unordered_set<string>s;
          for(int i = 0 ; i < textSize ; i++) {
              string newSubString = text.substr(i,textSize-i);
                   // if(s.find(doubleString) == s.end() && doubleString .size() <= textSize ) {
                        vector<int>zFun = STRSTR(newSubString);
                        for(int i = 1 ; i < zFun.size() ; i++) {      
                                if(zFun[i] >= i){
                                 s.insert(newSubString.substr(0,i));
                                }
                        }
                    } 
        return s.size();   
    }
};
 
/*

a b c a b c a b c
0 0 0 6 0 0 3 0 0 

l e e t c o d e l e e t c o d e
                3        
*/

/*

=======================================================================================
OPTIMIZATION 1:
16/40 PASSED REMAINGING NOT DUE TO TLE :  
class Solution {
public:
    vector<int> STRSTR(string text, string patt) {
           string con = patt + '$' + text ;
          int conLength = con.size();
          vector<int>zFun(conLength,0);
            int leftPtr = 0 ,rightPtr = 0;
            for(int curPtr = 1 ; curPtr < conLength ; curPtr++) {
            if(curPtr > rightPtr) {
                  rightPtr = leftPtr = curPtr;
                   while(rightPtr < conLength && con[rightPtr] == con[rightPtr-leftPtr]){
                    rightPtr++;
                   }
                   zFun[curPtr] = rightPtr -leftPtr ;
                   rightPtr--;
            } else{

               int index = curPtr - leftPtr;
                 if(zFun[index] < rightPtr-curPtr+1) {
                      zFun[curPtr] = zFun[index];
                 }
                 else{
                    leftPtr = curPtr;
                    while(rightPtr < conLength && con[rightPtr] == con[rightPtr-leftPtr]){
                    rightPtr++;
                   }
                   zFun[curPtr] = rightPtr -leftPtr ;
                   rightPtr--;
                 }
            }
        }
    return zFun;
   }
    int distinctEchoSubstrings(string text) {
         int count = 0 ;
          int textSize = text.size() ; 
          int subStringSize = (textSize-1)/2;
        set<string>s;
          for(int i = 0 ; i < textSize ; i++) {
              string newSubString = "";
             for(int j = i ; j < textSize ; j++) {
                    newSubString += text[j];
                    string doubleString = newSubString + newSubString;
                    if(s.find(doubleString) == s.end() && doubleString .size() <= textSize ) {
                               vector<int>zFun = STRSTR(text,doubleString);
                        for(int i = 0 ; i < zFun.size() ; i++) {
                                
                                if(zFun[i] == doubleString.size()){
                                      count++;
                                   s.insert(doubleString);
                                    break;
                                }
                        }
                    }      
             }
          } 
        return count;   
    }
};
==========================================================================================
    Testcases : 
      "a" = > 0 
      "abcdef" = > 0

    complete BruteForce solution :

14/40 passed and reamiang not due to TLE :
class Solution {
public:
   bool STRSTR(string text, string patt) {
       int textSize = text.size() , textPtr = 0;
       int pattSize = patt.size() , pattPtr = 0;
        for(; textPtr <= textSize - pattSize ; textPtr++ ) {
              pattPtr = 0;
              for(; pattPtr < pattSize ; pattPtr++) {
                  if(text[pattPtr + textPtr] != patt[pattPtr]) {
                          break;
                  }
              }
              if(pattPtr == pattSize) {return 1;}
        }
       return (textPtr == textSize && pattPtr == pattSize); 
   }
    int distinctEchoSubstrings(string text) {
         int count = 0 ;
          int textSize = text.size() ; 
          int subStringSize = (textSize-1)/2;
        set<string>s;
          for(int i = 0 ; i < textSize ; i++) {
              string newSubString = "";
             for(int j = i ; j < textSize ; j++) {
                    newSubString += text[j];
                    string doubleString = newSubString + newSubString;
                    if(s.find(doubleString) == s.end() && doubleString .size() <= textSize && STRSTR(text,doubleString)){
                         cout<<doubleString<<" ";
                        count++;
                        s.insert(doubleString);
                    }      
             }
          } 
        return count;   
    }
};



======================================================
 */
 // abcabcabc

// abcabc  bcabca  cabcab  abcabc bcabca cabcab abcabc 

/*
take few substring from text : 
            and 
            do add same substring  to substring and find that complete substing in text : 
             "abcabcabc"
        
            "a" + "a" = "aa" not found : 
              since i have to double it  takenNewSubstring <= text / 2 : 

            ab + ab = abab : search for this string in text : not found 
            abc + abc = abcabc : found : count = 1;

      abca + abca = abcaabca not found :   9%2  
             newSubstringsize  = (text-1)/2;

        abcab can't process this length : 
         start with : 
           b+b = bb not found : 
           bc+bc   not fouund : 

         like this i have to follow : 


          to genrate substing : text/ 2 * text / 2 
            
               to check in text whereht this usbstring presen tor not ..? (text * substringsize) : 
   

    TC : (text/2 * text /2 * text * text/2) :  since /2 we ignore : 
          O(textsize * textsize * text * text * logBaseno.ofValidSubstrings) : 
     SC : O(text/2 *text/2)  in linear array : 

          2000 * 2000 * 2000 *2000 
           2 * 2 * 2  *2  * 1000^4 
             16 * 10^4 :
        */