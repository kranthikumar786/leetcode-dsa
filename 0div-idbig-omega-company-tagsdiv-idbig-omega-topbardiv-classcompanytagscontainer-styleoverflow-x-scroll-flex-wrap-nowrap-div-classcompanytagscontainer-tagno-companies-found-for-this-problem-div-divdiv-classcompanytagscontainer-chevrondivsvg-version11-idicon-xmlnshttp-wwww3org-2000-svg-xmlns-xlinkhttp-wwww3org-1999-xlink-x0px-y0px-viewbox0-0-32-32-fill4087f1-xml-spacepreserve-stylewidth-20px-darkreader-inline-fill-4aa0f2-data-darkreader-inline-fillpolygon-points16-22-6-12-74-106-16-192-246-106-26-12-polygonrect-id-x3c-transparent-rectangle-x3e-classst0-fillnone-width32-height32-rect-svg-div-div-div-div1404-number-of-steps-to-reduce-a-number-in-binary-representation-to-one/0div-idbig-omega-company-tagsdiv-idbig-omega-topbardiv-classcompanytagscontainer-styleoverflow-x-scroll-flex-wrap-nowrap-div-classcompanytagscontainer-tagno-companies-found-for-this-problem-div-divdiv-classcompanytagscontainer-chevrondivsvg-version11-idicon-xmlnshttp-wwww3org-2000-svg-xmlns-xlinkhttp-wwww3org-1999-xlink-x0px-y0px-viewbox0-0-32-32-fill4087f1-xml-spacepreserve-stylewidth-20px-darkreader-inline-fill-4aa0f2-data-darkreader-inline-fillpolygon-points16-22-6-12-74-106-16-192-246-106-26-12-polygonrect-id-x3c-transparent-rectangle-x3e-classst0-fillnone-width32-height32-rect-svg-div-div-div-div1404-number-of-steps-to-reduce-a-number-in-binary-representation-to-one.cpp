class Solution {
public:
    
    void divideByTwo(string& s) {s.pop_back();}
    void addOne(string& s) {
        
        int i = s.size() - 1;
        
         while ( i >= 0 && s[i] != '0') {
             s[i] = '0';
             i--;
         }
          if( i < 0 ) {
              s = '1' + s;
          } else {
              s[i] = '1';
          }
    }
    int numSteps(string s) {
       int countSteps = 0 ;
        int N = s.size();
        while ( s.size() > 1) {
            N = s.size();
            if(s[N-1] == '0') {
                   divideByTwo(s);
             } else {
                 addOne(s);
             }
            countSteps++;
        }
        return countSteps;
    }
};

/*
"1101"
"10"
"1"
"0"  - > Not Accepted TC:

"10000000"
*/