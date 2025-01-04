class Solution {
public:
    bool isAlphaNumeric(char c) {
            return ((c - '0' <= 9  && c - '0' >= 0) || ( c >= 'a' && c <= 'z'));
    }
    bool isUpperCase(char c) {
            return (c >= 'A' && c <= 'Z');
    }

    bool isPalindromec(string s) {
        int leftPtr = 0 , rightPtr = s.length()-1;
        while(leftPtr <= rightPtr){
            if(s[leftPtr++] != s[rightPtr--]){
                return 0;
            }
        }
    return 1;
    }
bool isPalindrome(string s) {
   string str = "";
  for(char c : s){
      if(isUpperCase(c)){
         c = c + 32;
      }
      if(isAlphaNumeric(c)){
        str += c;
      }
  }
  cout<<str;
  return isPalindromec(str);
    }
};