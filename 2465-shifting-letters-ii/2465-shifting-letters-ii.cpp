class Solution {
public:
int mod(int a, int b) {
        return (a % b + b) % b;
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefixSum(s.size() + 1,0);
        for(auto & shift:shifts){
            int start = shift[0];
            int end = shift[1] + 1;
            int inc = (shift[2] == 1) ? 1:-1;
            prefixSum[start] -= inc;
            prefixSum[end] += inc;
        }
        int diff = 0;
        for (int i = prefixSum.size() - 1; i > 0; i --) {
            diff += prefixSum[i];
            s[i - 1] = mod(s[i - 1] - 'a' + diff, 26) + 'a';
        }
        return s;
    }
};
/*
          "abc" :  [[0,1,0],[1,2,1],[0,2,1]] : 

            "abc" : [0,1,0] :  
             
             zbc  : [1,2,1] : 
             zcd 

            zcd : [0,2,1] : 
            ade 
              
        */