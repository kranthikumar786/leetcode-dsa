class Solution {
public:
      vector<int>computeLPS(string pattern){
          int pattrenLength = pattern.size();
          int startingPtrWithLengthRef = 0 , movingIndex = 1;
            vector<int>computedLPS(pattrenLength,0);
           while(movingIndex < pattrenLength) {
              if(pattern[movingIndex] == pattern[startingPtrWithLengthRef]) {
                 computedLPS[movingIndex++] = ++startingPtrWithLengthRef;
              } else if(startingPtrWithLengthRef) {
                startingPtrWithLengthRef = computedLPS[startingPtrWithLengthRef-1];
              } else{
                movingIndex++;
              }
           }
          return computedLPS;  
      }
    string shortestPalindrome(string s) {
       string reveresS = string(s.rbegin(),s.rend());
         string combinedString = s + '$' + reveresS;
          vector<int>computedLPS = computeLPS(combinedString);
       int palindromeLength = computedLPS.back();
         string suffix = reveresS.substr(0,s.length()-palindromeLength);
          return suffix + s;
     }
    };
  /*


 LPS :
 "a a c e c a a a"
  0 1 0 0 0 1 2 0    
  ========================================
  "a a b b a"
   
    already matching 

have to add in middle : edge are matching : 
can be something like  : take already matching stirngtoaddnewcharString then add new mismatche to addNew char then do conString = newChar + substring where mismatch happening with help of leftptr and rightptr


  timeComplexity: (sLength * concatedStringLength) 
  spaceComplexity : O(sLength + addingnewchars) = O(concatedStringLength) 



void isPalindrome(string concatedString , int& leftPrt , int& rightPtr) {
           while(leftPrt <= rightPtr ) {
             if(concatedString[leftPrt] != concatedString[rightPtr]) {
                  break;
             }
              leftPrt++, rightPtr--;
           }
    }


string addingNewchar = "" ;
         for(int i = 0 ; i < s.length() ; i++){ 
            string concatedString = addingNewchar + s;
            int leftPtr = 0 , rightPtr = concatedString.length()-1;
          isPalindrome(concatedString ,leftPtr,rightPtr);
          if(leftPtr >= rightPtr ){
             return concatedString;
          }
          if(rightPtr  > leftPtr) { 
            addingNewchar =+ concatedString[rightPtr];
             
         }
        }
       return s;  
  
test cases : 

    edge case  : "" empty string is already palindrome :
     base case : "a" :  single char 
      
     already palindrome : "aba" : 
      sing char add :  "ab" addin b infront is fine: 


      now add more chars  like  more then half of oringal string 
          "abcd"  = > "dcbabcd"  leftptr == rightPtr
           "aabcd" : = > "dcbaabcd"   leftPTR > righPtr
            

  the max palindrom can be formed by adding same string in reveserly : 

    s= abcd : 
    revs = dcab 
    dcababcd : maxLength paldomr for given string : since we need to shortest one tha bove appraoch :

       0 1 2 3  
      a b c d 

    s = "aacecaaa"
      check already palindrome or not  : 
         a a  c e c  a a a 
              i      i 
 
      not matching of what char ..? 
      a so add a infrom of string : then re match it again ..

  
       a a a c e c a a a
           i        j 


        one function to check palndrom or not : 




        abcd 
        i  j   both are not matching ..
  i have add d at beging of string : 
  
          d + abcd : 
           d a b c d : 
             i   j : 


        string addingChar = dc 
        string orignalString = "abcd" : 

        String concateString = addingChar + orignalString;

   send concateString for palindrom check : 
          dc + abcd : 
           d c a b c d 
               i j


           add b infront string : 

    string addingChar = dcb 
        string orignalString = "abcd" : 

 
  String concateString = addingChar + orignalString; 

     dcb + abcd :

      d c b a b c d    if( i == j) { says palinfdrome formed with odd length}
            i

          d c b a a b c d    if( i >  j) { says palinfdrome formed with even length length}
                i j



     palindrom is nothing but same prefix which is also suffix : 
       aaa         aaa

   */

/*
const int n = s.size();
        int i = 0;
        for (int j=n-1; j>= 0; j--) {
            while (j>=0 && s[i] == s[j])
                i++, j--;
        }
        if (i==n) 
            return s;
        string sub= s.substr(i), remain_rev=sub;
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + sub;
*/