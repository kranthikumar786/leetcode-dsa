class Solution {
public:
    int minimumLength(string s) {
        
   unordered_map<char, int>charfrequencyMap;
    for(char  c: s) {
     charfrequencyMap[c]++;     
    }

  int ans = 0;
   for(auto itr = charfrequencyMap.begin(); itr != charfrequencyMap.end() ; ++itr){
          if(itr->second%2 == 1) {
             ans += 1;
          } else{
            ans += 2;
          }
   }
   return ans;

/*
  seems like palindrome : 


  s = "abaacbcbb"
        "bacbcbb"
        "babbb" : 
        "bab" : 
        a : 

    s = "a b a a c b c b b"
            
             after elimation : remove frwuncy remove it : 
         = "b a c b c b b" 
         = ""  right side first occurance remove cornal padage : 
         = "acbcb" :
            recheck the same b :  not  no need worry about ddoing sam eagain : 
         = "a c b c b" : 
                        right side : 

        map<char, int>mp ; 
      

      time compelity : O(n*n) 
      SC: O(n) : 
       for(int index = 0 ; index < n ; index++) {
             if(mp.count(s[index])) {
             curreIntdex ;
             while (right < n ) {
                   if(a[right] == s[curretindex]){
                 f = 1 ;
               s += s[right];
             }
              if(!f){
                s = OS;
              }
  } else{
    mp[s[index]]++;
  } 
               every time creatre new string by removing : 


 since i am trevasering from left tot right : from 0 to left iam awarof it count : 
  but if i  get count in rgiht side : as well : 
   that would be great :


   TC: O(n) : 
   SC :O(n)  +O(n) : 
           left side : present : map < char, index > righ tside also : map<char,rightside> 
          
           




         "bacbcbb" 
         "abbb" : 
          "ab" :
      "bacbccb" : 
      "acbcc" : 
       length 5 : 
*/

    }
};