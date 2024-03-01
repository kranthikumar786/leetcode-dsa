class Solution {
public:
    string maximumOddBinaryNumber(string s) {
      int givenLength = s.length();   
     int start = 0 , endIndex = givenLength - 1 ;
           int endL = endIndex;
       while (endL >= 0) {
          
            if(s[endL] == '1') {
                swap(s[endL] , s[endIndex]);
                break;
            } 
           endL--;
       }
        
             givenLength-= 2;
        while (start < givenLength) {
            
            if(s[start] == '1' || s[start] == '1' && s[givenLength] == '1') {
                 start++;
            }
            else if(s[start] == '0' && s[givenLength] == '1') {
                swap(s[start],s[givenLength]);
                start++;
                givenLength--;
            } 
             else {
                 givenLength--;
             }
        }  
        return s;
    }
};

/*

Test cases : 
"010" =  >pass
0101 =>pass
111111 : pass
000001 : =>pass
100000 =>pass


01010 :  10001  => 
010101 : 11001 => 


*/