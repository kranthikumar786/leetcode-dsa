class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
       int count = 0;
      int wordsSize = words.size() ;
       for(int i = 0 ; i < wordsSize ; i++) {
          for(int  j = i+1 ; j < wordsSize ; j++ ) {
              int curLPtr = 0 , leftPtr = 0 ;
         while(curLPtr < words[i].size() && leftPtr < words[j].size()&& words[i][curLPtr] == words[j][leftPtr]) {
                     curLPtr++;leftPtr++;
            }
        int curRptr = words[i].size()-1,rightPtr = words[j].size()-1;
           if(curLPtr  == curRptr+1){ // avoid looking for suffix  if no prefix found 
            while(rightPtr >= 0 && curRptr >= 0 && words[i][curRptr] == words[j][rightPtr]) {
                  rightPtr--;curRptr--;   
            } 
            }
          if(curRptr == -1){
            count++;
          }  
          }
       }
return count;    
    }
};

  /*
   TC : O(n*n*(n + n)) : 
   SC : O(1) : 
  */    
      



//   vector<int>buildLPS(string s) {
    
//   }
/*
vector<int>zFun(string s) {
        int sLength = s.size();  
        vector<int>ZFUN(sLength,0);
        int  leftPtr = 0, rightPtr = 0;
        for(int curPtr = 1; curPtr < sLength ; curPtr++) {
               if(curPtr > rightPtr) {    
                    leftPtr = rightPtr = curPtr ;
                    while(rightPtr < sLength && s[rightPtr] == s[rightPtr - leftPtr]) {
                      rightPtr++;
                    }
                    ZFUN[curPtr] = rightPtr - leftPtr;
                    rightPtr--;
               } else{
                     int index = curPtr - leftPtr;
                     if(ZFUN[index] < rightPtr - curPtr +1) {
                         ZFUN[curPtr] = ZFUN[index];
                       }
                       else{
                          leftPtr = curPtr ;
                          while(rightPtr < sLength && s[rightPtr] == s[rightPtr - leftPtr]) {
                           rightPtr++;
                           }
                          ZFUN[curPtr] = rightPtr - leftPtr;
                         rightPtr--;
                        }
               }
            } 
      return ZFUN;
      }
    int countPrefixSuffixPairs(vector<string>& words) {
       int count = 0;
      int wordsSize = words.size() ;
       for(int i = 0 ; i < wordsSize ; i++) {
          for(int  j = i+1 ; j < wordsSize ; j++ ) {
              vector<int>Zfun = zFun(words[i] + "$" + words[j]);
              //int maxRadius = 0 , maxRadiusIndex  = 0 ;
             for(int k = 0 ; k < Zfun.size() ; k++) {
                    if(words[i].size() == Zfun[k]) {
                     //  cout<<words[i]<<" "<<words[j]<<" \n"; //: 
                     //  //  cout<<Zfun[i]<<" ";
                    //     maxRadius = Zfun[i];
                    //     maxRadiusIndex = i;
                    // }
                    count++;
                     break;
              }
         }
       }}
return count;    
    }
};

/*

TC Fail:  ["a","abb"]
       E/O : 0 
       A/O : 1 
======================================================================================
       a%$abb :  so Zfun only works for longest prefix : Not for prefix and suffix : 

       I think we can use KMP : LPS : 

       
================================================================================== 
 TC : O(n*n*(n+m))
 SC : O(n+m):

class Solution {
public:
  
vector<int>zFun(string s) {
        int sLength = s.size();  
        vector<int>ZFUN(sLength,0);
        int  leftPtr = 0, rightPtr = 0;
        for(int curPtr = 1; curPtr < sLength ; curPtr++) {
               if(curPtr > rightPtr) {    
                    leftPtr = rightPtr = curPtr ;
                    while(rightPtr < sLength && s[rightPtr] == s[rightPtr - leftPtr]) {
                      rightPtr++;
                    }
                    ZFUN[curPtr] = rightPtr - leftPtr;
                    rightPtr--;
               } else{
                     int index = curPtr - leftPtr;
                     if(ZFUN[index] < rightPtr - curPtr +1) {
                         ZFUN[curPtr] = ZFUN[index];
                       }
                       else{
                          leftPtr = curPtr ;
                          while(rightPtr < sLength && s[rightPtr] == s[rightPtr - leftPtr]) {
                           rightPtr++;
                           }
                          ZFUN[curPtr] = rightPtr - leftPtr;
                         rightPtr--;
                        }
               }
            } 
      return ZFUN;
      }
    int countPrefixSuffixPairs(vector<string>& words) {
       int count = 0;
      int wordsSize = words.size() ;
       for(int i = 0 ; i < wordsSize ; i++) {
          for(int  j = i+1 ; j < wordsSize ; j++ ) {
              vector<int>Zfun = zFun(words[i] + "$" + words[j]);
              //int maxRadius = 0 , maxRadiusIndex  = 0 ;
             for(int k = 0 ; k < Zfun.size() ; k++) {
                    if(words[i].size() == Zfun[k]) {
                     //  cout<<words[i]<<" "<<words[j]<<" \n"; //: 
                     //  //  cout<<Zfun[i]<<" ";
                    //     maxRadius = Zfun[i];
                    //     maxRadiusIndex = i;
                    // }
                    count++;
                     break;
              }
         }
       }}
return count;    
    }
};
*/
          // int startIndex =  maxRadiusIndex - maxRadius-1;
           //  cout<<startIndex <<"  "<<maxRadius <<" " <<maxRadiusIndex<<" "; 
            //    cout<<words[j].substr(startIndex, maxRadius)<<"\n";
            //if(words[j].substr(startIndex, maxRadius) == words[i])
              //    count++;
              /*                              
                           0 0 3 0 0       maxRadius = 3 :                
                 "aba"  : "z a z a z" :   size : 3 prefix and suffix :  but not presnt : 
                           0 1 2 3 4   centerIndex = 2 :
                                                         3- 2 +1       
                      now i will get startin index = maxRadius - centerIndex +1 ; 

                      let's say : zfun store all the occurance of size of prefix and suffix : 
                      which 3 has to be takenn..? 
                        since it is prefix means starting reamins same : so : 
                         if it is having at mupllte places also  : we take lastone or first  works

                    so wht have to done  here is : if
                    */
//              if(words[i].size() == Zfun.back()) 

               /* s1 = "aba* 
                s2 = "abakkkkaba" : here it is true : 
                   but if i use zfun : it gives flase: becuase it is compltely : 
                  */
                //  count++;
          
  //        for(int i = 0; i < Zfun.size(); i++) {
    //          cout<<Zfun[i]<<" ";
         // }


//   ==============================================================================   

  /*
   TC : O(n*n*(n + n)) : 
   SC : O(1) : 

   int countPrefixSuffixPairs(vector<string>& words) {
       int count = 0;
      int wordsSize = words.size() ;
       for(int i = 0 ; i < wordsSize ; i++) {
           // string str1 = words[i];
          for(int  j = i+1 ; j < wordsSize ; j++ ) {
            //string str2 = words[j];
              int curLPtr = 0 , leftPtr = 0 ;
         while(curLPtr < words[i].size() && leftPtr < words[j].size()&& words[i][curLPtr] == words[j][leftPtr]) {
                     curLPtr++;leftPtr++;
            }
        int curRptr = words[i].size()-1,rightPtr = words[j].size()-1;
           if(curLPtr  == curRptr+1){ // avoid looking for suffix  if no prefix found 
            while(rightPtr >= 0 && curRptr >= 0 && words[i][curRptr] == words[j][rightPtr]) {
                  rightPtr--;curRptr--;   
            } 
            }
          if(curRptr == -1){
            count++;
          }  
          }
       }
return count;    
    }
};
  */    
      
        /*
           ["a","aba","ababa","aa"]

           "a" , "aba" : 
           'a' : 'aba' =  >true : count++ ;
        
           'a' : "ababa" : = > a and a : count ++
                   
             str2 = "a"  str1 = "ababa" : traves the str1 of size str2 : 
              
              both both :  "ababa" : lucky both are same : 
                            "bcdcb" : here both are same but not matchng with : str2 : so :
                              also check the  while ( i < str2.size() && left  >= 0 && right < str1.size() rightstr2[i] == str1[left]  && str2[i] == str1[right] : 
                                           move i++ ; left++; right++;
                                        if( i == str2.size()) :
                                              cnt++;         
           'a' : 'ababa' : - > count++;
           'a' : 'aa' - > count++;
        */
