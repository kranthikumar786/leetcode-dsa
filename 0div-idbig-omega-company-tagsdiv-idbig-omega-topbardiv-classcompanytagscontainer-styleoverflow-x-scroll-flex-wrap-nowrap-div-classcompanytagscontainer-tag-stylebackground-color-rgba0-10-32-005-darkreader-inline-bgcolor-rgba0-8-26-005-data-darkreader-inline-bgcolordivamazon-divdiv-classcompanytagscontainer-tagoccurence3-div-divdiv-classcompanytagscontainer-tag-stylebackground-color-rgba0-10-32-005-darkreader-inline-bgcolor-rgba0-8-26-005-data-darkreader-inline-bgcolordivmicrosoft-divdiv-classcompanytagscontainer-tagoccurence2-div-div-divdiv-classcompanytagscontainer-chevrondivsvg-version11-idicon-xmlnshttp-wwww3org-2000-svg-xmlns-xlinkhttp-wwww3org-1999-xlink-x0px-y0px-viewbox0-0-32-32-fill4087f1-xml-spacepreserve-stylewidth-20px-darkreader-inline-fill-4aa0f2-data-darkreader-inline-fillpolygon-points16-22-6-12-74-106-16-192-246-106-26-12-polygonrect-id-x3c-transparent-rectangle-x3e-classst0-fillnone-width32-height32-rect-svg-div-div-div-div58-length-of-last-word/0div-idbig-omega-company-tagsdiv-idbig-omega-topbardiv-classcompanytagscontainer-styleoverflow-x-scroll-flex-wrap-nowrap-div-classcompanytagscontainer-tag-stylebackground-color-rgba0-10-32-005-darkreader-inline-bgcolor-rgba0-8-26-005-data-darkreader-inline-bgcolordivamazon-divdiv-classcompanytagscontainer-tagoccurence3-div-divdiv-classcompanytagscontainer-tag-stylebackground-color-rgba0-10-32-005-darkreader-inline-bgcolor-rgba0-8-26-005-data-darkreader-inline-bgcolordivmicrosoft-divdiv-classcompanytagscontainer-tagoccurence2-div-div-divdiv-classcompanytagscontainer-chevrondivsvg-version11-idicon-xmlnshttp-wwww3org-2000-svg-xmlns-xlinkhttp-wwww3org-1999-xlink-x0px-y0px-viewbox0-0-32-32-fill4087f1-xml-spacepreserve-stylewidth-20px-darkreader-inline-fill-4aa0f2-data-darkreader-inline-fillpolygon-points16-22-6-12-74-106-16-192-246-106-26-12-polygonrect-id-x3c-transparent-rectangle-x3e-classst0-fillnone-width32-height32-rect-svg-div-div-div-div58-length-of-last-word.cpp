class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.length();
  bool Word = 0;
     int length = 0 ;
        for (int  i = n - 1 ; i >= 0 ; i--){

                  if(s[i] == ' ' && Word) {
                        return length;
                  }

               else if (s[i] == ' ' && !Word){
                       
                }  
                else{
                    length++;
                    Word = 1;
                }
        }
        return length;
    }
};