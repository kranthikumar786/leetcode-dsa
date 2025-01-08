class Solution {
public:
    long long calculateScore(string s) {
        long long score = 0;
        int sSize = s.size();
       unordered_map<char, vector<int>>charPos;
        for (int i = 0; i < sSize; i++) { 
             char mirror = 'z' - (s[i] - 'a'); 
        if(charPos.find(mirror) != charPos.end() && charPos[mirror].size() > 0){
                 int closetIndex = charPos[mirror].back();
                   charPos[mirror].pop_back();
                 score += (i -closetIndex);  
            }
            else{
                charPos[s[i]].push_back(i);
            }
        }
        return score;
  }
};

/*
 tc : O(n) 
 sc : O(26 * n) : 

*/

      /*
      
 "a a a a a a a b b b b b b b " : 
  a - > 0 ,1 ,2,3,4,5,6 : 
  b - > 7 , 8, 9, 10 ,11,12 : 
  c - > 

  "abcdef" : 

  a - >0 : 
  b - >1 : 
  c - >   




 0 1 2 3 
"a a z z" : 
 z z  

2- 0  =2 : 
3 - 1 = 2 : 
2 +2 : 4 : 
so duplicates working like this : 



      "e o c k p p x d q c l k h j g v n w" : 







   long long score = 0;
        int sSize = s.size();
        vector<bool> visited(sSize, false); 
        for (int i = 0; i < sSize; i++) { 
             char mirror = 'z' - (s[i] - 'a'); 
            for (int j =  i -1 ; j >= 0; j--) {
                  // missing this  closest unmarked index j
                if (!visited[j] && !visited[i] && s[j] == mirror) { 
                    score += (i - j);
                    visited[j] = true;
                    visited[i] = true;
                    //  missed this too mark both indices i and j,  
                    break;
                }
            }
        }
        return score;
  }
};


 AO : 54 : 
  EO: 50 : 

      'azbycx' ..? 3 : 
       "aczzx" : duplciate already coved 
       "abcdef" kind of lexig sorted done : 
       "fedcba" : also coved : 



      tc : O(n*n) : 
      so TLE can be expcted : 


      */
//       x
//       a
// a  a  0
// a
// a  a  -2
// c
// c  c  -5

        /*
        Input: s = "aczzx"

Output: 5

         i = 0  : 
         i = 1 : 
          i = 2 : 
              s[i = 2] = z  - 'a' %26 :  prestn in left side :   
                yeps present at index j = 0 : 
                   mark it : 
                   score += (i - j ): 
             j < i  :  

           i = 3 : 
            z  : but a alrady used and mraked too : hence no match found : 
            i = 4 : 
            char mirror =  char(x-'a' %26) :    
               for(int j = 0 ; j < i ; j++) {
                  if(s[j] == mirrror) {
                       score +=  (j- i);
                        s[j] == '@';
                         break;
                  }
               }
              
        */
   