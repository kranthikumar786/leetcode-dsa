class Solution {
public:
    bool isVowel(char c) {
          return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
    }
   void preComputeWithPrefixSum(vector<int>& preCalculateVowelStartAndEndwords){
        int  n = preCalculateVowelStartAndEndwords.size();
        for(int ptr = 1 ; ptr < n ; ptr++) {
           preCalculateVowelStartAndEndwords[ptr] += preCalculateVowelStartAndEndwords[ptr-1];
        }
    }
  void markWordStartsAndEndswithvowel(vector<string>& words,vector<int>& preCalculateVowelStartAndEndwords){
           int wordsSize = words.size();
          for(int wordIndex = 0 ; wordIndex < wordsSize ; wordIndex++) {
               string word = words[wordIndex];
                if(!word.empty() && isVowel(word[0])&& isVowel(word.back())) {
                     preCalculateVowelStartAndEndwords[wordIndex] = 1;        
                 }
           }
    }
   vector<int> countAllWordsStartsAndEndsWithVowel(vector<int>preCalculateVowelStartAndEndwords,vector<vector<int>>& queries){
         vector<int>ans;
         int qSize = queries.size();
             for(int query = 0 ; query < qSize ; query++) {
                int li = queries[query][0];
                int ri = queries[query][1];
                int count = (li != 0 ? preCalculateVowelStartAndEndwords[ri] - preCalculateVowelStartAndEndwords[li-1] : preCalculateVowelStartAndEndwords[ri]);
                ans.push_back(count);
             }
      return ans; 
     }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;
       int wordsSize = words.size();
        vector<int>preCalculateVowelStartAndEndwords(wordsSize , 0);
        markWordStartsAndEndswithvowel(words,preCalculateVowelStartAndEndwords);
        preComputeWithPrefixSum(preCalculateVowelStartAndEndwords);
    return countAllWordsStartsAndEndsWithVowel(preCalculateVowelStartAndEndwords,queries);
       }
};
 /*
  timeComplexity:  O(wordsSize) + O(wordsSize) + O(qSize)
  spaceComplexity: O(wordSize) 
 */
       /*
       
         what can be optimzed ..? 


  this remians same :  for each word i have to check whetehr stating and ending with vowel or not : 
if(!word.empty() && isVowel(word[0])&& isVowel(word.back())){
                            count ++;
}


---------------------------
 here finding for everyrange  word  start is vowel or not ... 

int count = 0;
                 int li = queries[query][0];
                 int ri = queries[query][1];
for(;li <= ri; li++ ) {
                   string word = words[li] ;
                      if(!word.empty() && isVowel(word[0])&& isVowel(word.back())){
                            count ++;
                      } 
                  }



     since we are soing for range based word : let's find at begining every word start and end vowel  ..? 


let's say : 

 for(wordIndex = 0 ; wordIndex < wordsSize ; wordIndex++) {
         string word = words[wordIndex];
    if(!word.empty() && isVowel(word[0])&& isVowel(word.back())) {
              prefix[wordIndex] = 1;
    }
 }

 ["aba","bcb","ece","aa","e"]
    1     0     1     1   1 

 for(int i = 1 ; i < prefixSum ; i++) {
      prefixSum[i] += prefixSum[i-1]; 
 }

  [1,1,2,3,4] : 
 for(int query = 0 ; query < qSize ; query++ ) {
           int li = querie[query][0];
           int ri = querie[query][1];
           int count = (li != 0 ? prefixSum[ri] - prefixSum[li-1] : prefixSum[ri]);
         ans.push_back(count); 
 }
   now : 
   sum it : 
       */

         /*
         for(int  query = 0 ; query < qSize ; query++) {
                 int count = 0;
                 int li = queries[query][0];
                 int ri = queries[query][1];
               for(;li <= ri; li++ ) {
                   string word = words[li] ;
                      if(!word.empty() && isVowel(word[0])&& isVowel(word.back())){
                            count ++;
                      } 
                  }
                
             ans.push_back(count);  
             }
    return ans;
    }
};
TimeComplexity: O(Qsize*TotalLenghtofWords*eachStringforCopy)
SpaceComplexity:  O(1) as return type vector not counted

 Verdict : we can expect TLE: 
 10^5 * 10^5 * 3 * 10^5 = 
 3*10^15

 93/94 TC passed: 

Test cases1 : 

 count = 0 answer  with worst case time Complexity: O(Qsize*TotalLenghtofWords*eachStringforCopy) 

  ["zaz" , "rar" , "tat" , "sdfghjkl" ]
   Q[[0,4], [0,4], [0,4]] : 

 A/O : [0,0,0] E/O : [0,0,0]
=======================
TC2 : 

answer existing  with worst case time Complexity: O(Qsize*TotalLenghtofWords*eachStringforCopy) 

  ["aza" , "eae" , "iai" , "odfghjk0" ]
   Q[[0,3], [0,3], [0,3]] : 

 A/O : [4,4,4,4] E/O : [4,4,4,4]


 since it not like search for some element so we have to check all possbilities so we always end up with worst case time complexity : 


  followUpQuestions to gather more information:

 Input : 

    1. only lowercase 
    2. any empty string possible ..? yes 
    3. order matter ..? nopes
Processing : 

      deal with empty string carefully  :

 Output : 
  if answer exisint :
 simply retrun list of value 
  if no answer : empty() list :
  each Query  [0,2] :  O(Qsize)
         find in words :   :   O()
 
*/