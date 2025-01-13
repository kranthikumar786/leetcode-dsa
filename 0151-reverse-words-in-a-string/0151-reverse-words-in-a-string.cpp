class Solution {
public:
    string reverseWords(string s) {

      stack<string>st;
      string temp = "";
       int  n = s.length();
       for(int i = 0 ; i < n ; i++) {
         if(s[i] == ' ' && temp.length() == 0 ) {
              continue;
         } else if(s[i] == ' ' && i+1 < n  && s[i+1] == ' ') {
                 continue;
         }
         else if ( s[i] == ' ' && i+1 < n && s[i+1] != ' ' ) {
               st.push(temp);
               temp = "";
         } else if(s[i] == ' ' && i+1 == n){
             st.push(temp);
              temp = "";
         } 
         else{
            temp += s[i];
         }
       }
       if(temp.length()){
        st.push(temp);
       }
       temp = "";
        while (st.size()){
             temp += st.top();
              st.pop();
             if(st.size() != 0) {
                 temp += " ";
             }
        } 
   return temp;
    }
};

/*
Input: s = "hello world  "

*/