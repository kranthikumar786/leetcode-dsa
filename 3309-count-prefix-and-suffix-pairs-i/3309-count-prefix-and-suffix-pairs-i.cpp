class Solution {
public:
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

  /*
   TC : O(n*n*(n + n)) : 
   SC : O(1) : 
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
