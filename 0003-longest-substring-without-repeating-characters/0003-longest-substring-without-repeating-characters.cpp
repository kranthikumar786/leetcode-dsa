class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_set<char>se;
  int leftPtr = 0 ,rightPtr = 0,n = s.length();
   if( n == 0) { return 0;}
   int ans = 0; 
     while(rightPtr < n){
        while(se.size() && se.find(s[rightPtr]) != se.end()){
             se.erase(s[leftPtr]);
            leftPtr++; 
        }
      se.insert(s[rightPtr]);
      ans = max(ans, rightPtr-leftPtr);
      rightPtr++;
     }
     return ans+1;
    }
};


/*


 genrate all substrings meanwhile check the  longest  substring without repeating
    tc : O(n*n*n)
    sc : O(26) :

  approach 2: 
  
    traverse using two ptrs meanshiwl stroing all the chars in set , 

     if char found : remove it from set  :  and also move leftptr till leftside reaching of char : 

      tc :O(n) : 
      sc : O(n)

       // "a b c b b c b b"

    //      a,b,c,b : 
    //      0,1,2,3 

"abcdefe" 
"abcbbcbb"
*/