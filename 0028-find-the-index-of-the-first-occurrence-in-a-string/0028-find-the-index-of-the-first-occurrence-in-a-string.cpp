class Solution {
public:
  vector<int> zFunc(string text , string pattern) {
      string concatedString = pattern + '$' + text ;
      int concatedStringLength = concatedString.size();
     vector<int>indicesOfSubstringAlsoPrefix(concatedStringLength,0);
      int prefixWindowLeftPtr = 0 , prefixWindowRightPtr = 0; 
    for(int currentIndex = 1 ; currentIndex < concatedStringLength ; currentIndex++) {
      if(currentIndex > prefixWindowRightPtr) {
          prefixWindowRightPtr = prefixWindowLeftPtr =  currentIndex ;
          while(prefixWindowRightPtr < concatedStringLength && concatedString[prefixWindowRightPtr] == concatedString[prefixWindowRightPtr-prefixWindowLeftPtr]){
                   prefixWindowRightPtr++;    
          }
           indicesOfSubstringAlsoPrefix[currentIndex] = prefixWindowRightPtr - prefixWindowLeftPtr;
           prefixWindowRightPtr--;
      } else{
              int beginingIndex = currentIndex - prefixWindowLeftPtr ;
              if(indicesOfSubstringAlsoPrefix[beginingIndex] < prefixWindowRightPtr - currentIndex +1){
                  indicesOfSubstringAlsoPrefix[currentIndex] = indicesOfSubstringAlsoPrefix[beginingIndex];  
              }
         else{
            prefixWindowLeftPtr = currentIndex;
             while(prefixWindowRightPtr < concatedStringLength && concatedString[prefixWindowRightPtr] == concatedString[prefixWindowRightPtr-prefixWindowLeftPtr]){
                   prefixWindowRightPtr++;    
          }
           indicesOfSubstringAlsoPrefix[currentIndex] = prefixWindowRightPtr - prefixWindowLeftPtr;
           prefixWindowRightPtr--;

         }
      }
    }
   return  indicesOfSubstringAlsoPrefix;    
  }
  int strStr(string haystack, string needle) {
      if(needle.size() > haystack.size()) return -1;
     vector<int>zfun = zFunc(haystack,needle);
   for(int i = 0 ; i < zfun.size() ; i++) {
       if(zfun[i] == needle.size()){
           cout<<zfun[i] <<" ";
         return  i - needle.size() -1; 
       }
   }
   // "sadbutsad"
   // 2
   // 0
      // sad = 3
    // 0 1 2 3 4 5 6 7 8 9 10 11 12
    // s a d $ s a d b u t s   a  d :
  //   0 0 0 0 3 0 0 0 0 0 3   0  0 : 
    return -1;
  }
  };

/*
Z-algo : 

prefix as substring  also this helps  find the occurance of pattren in text:
 s = "s a d b u t s a d" , p = "s a d"     
  cs =  p + '$' + s ;
        0 1 2 3 4 5 6 7 8 9 10 11 12
  cs = "s a d $ s a d b u t s  a  d";
                i   r           
       [0,0,0,0,3,0,0,0,0,0,0, 0, 0]


    4 > 6 is false
  else{
       
       newIndex = i - l (4-4) : 0 : 
       z[0] < 6  - 4 +1 (0 < 3) 
         
         z[4] = z[0] = 0 ;:

       i++ ;

       new Index = 5 - 4 
         z[1]  < 6 - 5 +1 (0  < 2) : 
         z[5] = z[1] ( 0 = 0)


  }  
           if(i > r): 
            l = r = i ;
             while(r < csSize  && cs[r] == cs[r-l]){
                  r++;
             }
              z[i]  = r-l;
               r--; 
         else {

                 int newI = i -l ;
                   if(z[newI] < r - i +1) {
                       z[i] = z[newI];
                   }
              else{
                  l = i ;
                  while(r < csSize  && cs[r] == cs[r-l]){
                      r++;
                  }
                  z[i] = r- l;
                  r--;
              }
         }

class Solution {
public:


    int strStr(string haystack, string needle) {
      int needleLength = needle.length();
      int haystackLength = haystack.length();
   vector<int>LPS(needleLength, 0);
    buildLPS(needle, needleLength , LPS);
   int needlePtr = 0 , haystackPtr = 0;
     while(haystackPtr < haystackLength) {
          if(needle[needlePtr] == haystack[haystackPtr]) {
               haystackPtr++;
               needlePtr++;
          }
           if(needlePtr == needleLength ){
              return haystackPtr - needlePtr;
           } else if(haystackPtr < haystackLength && needle[needlePtr] != haystack[haystackPtr]) {
             if(needlePtr != 0){
                needlePtr = LPS[needlePtr-1]; 
             } else{
                haystackPtr++;
             }
           }
     }
        return -1;
    }
private:
   void buildLPS(string &needle , int n , vector<int>&LPS){
      int startingPtrWithLengthRef = 0 ; 
      int movingIndex = 1;
        LPS[0] = 0; 
      while(movingIndex < n) {
            if(needle[movingIndex] == needle[startingPtrWithLengthRef]) {
                LPS[movingIndex++] = ++startingPtrWithLengthRef;
            } else {
                 if(startingPtrWithLengthRef != 0) {
                     startingPtrWithLengthRef = LPS[startingPtrWithLengthRef-1];
                 } else{
                    LPS[movingIndex++] = 0;
                 }
            } 
      }
   }
    };
  /*
    int needleLength = needle.size();
    int  haystackLength = haystack.size();
     for(int hayStackIndex = 0 ;hayStackIndex <= haystackLength - needleLength ; hayStackIndex++){
         
         /*    int needledIndex = 0;
              for(; needle[needledIndex] ; needledIndex++) {
                 if(needle[needledIndex] != haystack[hayStackIndex+needledIndex]) {
                       break;
                 }
              }   
                 if(needledIndex == needleLength){
                     return hayStackIndex;
        }
   if(haystack.substr(hayStackIndex , needleLength) == needle){
      return hayStackIndex;
   }
    }
        return -1;
  }
};

lee t l e  e t l e e  t  l  e  e  t  c
012 3 4  5 6 7 8 9 10 11 12 13 14 15 15 
l e e t c
0 1 2 3  4 
*/
/*
 Evalutiona paramters: 
  timeComplexity : O((haystack.length() - needle.length()) * (needle.length())
  spaceComplexity : O(1) 
*/

/*TC : 
// "sadbutsad" 
// "sad"

=====
""
""
====
"a"
"ab"
=====


 ANSWER FOUND TC: 

avg  TC: 
"abcd"
"c"
==========
Worst TC: 
 "abcd"
 "d"


 99% string match : 
  haystack = "leetcodleectcodleectcodleectcodleectcode" needle = "leetcode" 

    almost matches but  went for perfet perfect match : 


========

Best TC
"abcd"
"a"

==============
 answer not found TC: 
  is always worst case :  



probelm spefic TC: 

 first occruance :  so let's have tc which is having mmore then one occurance: 

 exmaple 1 : 
     haystack = "sadbutsad" , needle = "sad"


   TC: 



  99% string match : 
  haystack = "leetcodleectcodleectcodleectcodleectcode" needle = "leetcode" 

    almost matches but  went for perfet perfect match : 


  half mtach  : 50% match :

   haystack = "leetleectcode" , needle = "leetcode"
      50% match  at first but later went  to get prefetc match : 


 not at all matching : 
  
   haystack ="hello world iam good at coding " , needle = "iam good" : 


*/ 
        /*
           
         approach : 
          outloop with haystack and innner loop with needle string :

     input : 
            empty "" 
            answer not possible case  like needle .lenght > haystack
            only lowercase or upper caser and  any special chars or digits in it.
              directly string and no words hence no sepration too
             even or odd lenght makes any diffurance..?
             edge case :  last char matching with needle : 
            bounday case : 
           duplicate  or any order 
            lexigraphicall sorted 
    
    processing : 
      
        any chane of arthermteic overflow .. ? nopes .



    Output : 
  
      answer exisint 
              single answer  .. ? easy simply return ans
              or mulple answers possible  what to retur ..?  first answer return     
        answer do not exist : 
          -1 
       
        any lexicographicall .?

       Testcases shoulbe be : 
       TC and SC complexity :
        TC: 
        Best  : O(needlel) : found occurance  at first  needle lenth in  haystack
        Avg case  : O(n/2) :  finding  occuarance in middle 
                          ex : haystack  = "hello " needle "ll"
        Worst case : O(n) : to  finidng occruance  reach till the end of the haystack 
                         ex : haystack = "hello" , needle  = "o"


       SC : 


           O(1) :  for best , avg and worst cases it remains same                                         
             if(h[i] == n[j]) {
                 if(index != -1){
                     index = i;
                 }
                 j++; 
                 i++;
             }
              esle{
                i++;
              }
  return index;
        
        */

  