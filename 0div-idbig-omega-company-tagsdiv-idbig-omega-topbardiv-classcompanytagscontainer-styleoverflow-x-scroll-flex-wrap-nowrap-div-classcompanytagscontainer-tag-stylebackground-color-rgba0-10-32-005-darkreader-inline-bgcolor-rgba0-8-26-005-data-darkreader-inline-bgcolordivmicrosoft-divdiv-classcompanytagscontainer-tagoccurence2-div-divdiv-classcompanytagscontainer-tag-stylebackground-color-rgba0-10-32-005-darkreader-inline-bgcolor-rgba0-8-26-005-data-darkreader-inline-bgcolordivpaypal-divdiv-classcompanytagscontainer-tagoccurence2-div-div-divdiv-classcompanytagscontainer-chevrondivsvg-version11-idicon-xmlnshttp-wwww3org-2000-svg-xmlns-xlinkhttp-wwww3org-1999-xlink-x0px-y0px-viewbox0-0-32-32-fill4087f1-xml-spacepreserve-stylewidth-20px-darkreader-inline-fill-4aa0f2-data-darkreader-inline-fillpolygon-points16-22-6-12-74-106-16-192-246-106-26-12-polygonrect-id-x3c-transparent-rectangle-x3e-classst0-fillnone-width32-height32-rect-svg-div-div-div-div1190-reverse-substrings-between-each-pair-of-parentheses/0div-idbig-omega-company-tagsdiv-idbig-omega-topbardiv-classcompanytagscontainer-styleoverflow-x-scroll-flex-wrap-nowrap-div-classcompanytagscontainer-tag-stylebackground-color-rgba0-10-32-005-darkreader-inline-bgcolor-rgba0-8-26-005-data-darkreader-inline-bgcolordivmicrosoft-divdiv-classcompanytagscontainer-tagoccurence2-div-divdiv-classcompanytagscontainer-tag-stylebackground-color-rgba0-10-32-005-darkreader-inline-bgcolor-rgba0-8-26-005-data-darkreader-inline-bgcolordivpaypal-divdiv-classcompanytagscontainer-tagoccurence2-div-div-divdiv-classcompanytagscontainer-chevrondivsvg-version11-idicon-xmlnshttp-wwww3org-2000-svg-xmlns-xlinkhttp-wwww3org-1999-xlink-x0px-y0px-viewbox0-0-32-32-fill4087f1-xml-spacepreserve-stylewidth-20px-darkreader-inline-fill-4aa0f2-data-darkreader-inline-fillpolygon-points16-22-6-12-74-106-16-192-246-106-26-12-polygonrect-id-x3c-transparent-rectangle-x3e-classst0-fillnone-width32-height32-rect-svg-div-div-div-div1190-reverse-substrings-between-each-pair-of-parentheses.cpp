class Solution {
public:
    string reverseParentheses(string s) {
        vector<int>opend;
        string res;
        for(char ch : s) {
             if(ch == '(') {
                  opend.push_back(res.length());
             } else if(ch == ')') {
                   int st = opend.back();
                          opend.pop_back();
                    reverse(res.begin() + st , res.end()); 
             } else {
                  res += ch;
             }
        }
       return res; 
    }
};