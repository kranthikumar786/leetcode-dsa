/*bool isLowerCase(char c){
      return (c>='a' && c<='z');}
    char toUpperCase(char c){
        return c-32;}
    char toLowerCase(char c){
         return c+32;}
       */  
class Solution {
public:
    string makeGood(string s) {
         string st;
        int n=s.length();
        // if(n<=1) return s;
        for(auto i:s){
            if(st.empty())
             st.push_back(i);
            else if((st.back()^32)==i){
                //cout<<st.back();
                st.pop_back();
             }
            /*else if(!isLowerCase(st.back()) && toLowerCase(st.back()==i))
            {   cout<<st.back();
                st.pop_back();}*/
            else  
                st.push_back(i);
        }
        return st;
    }
};