class Solution {
public:

    bool hasMatch(string s, string p) {
       int sLength = s.size(), pLength = p.size();
       int startIndex = p.find('*');
       string  leftSubString = p.substr(0,startIndex);
       string rightSubString = p.substr(startIndex+1);
       int i = s.find(leftSubString);
       int j = s.rfind(rightSubString);
     return i != -1 && j != -1 && i + leftSubString.size() <= j;
        /*
        s="leetcode" , p="ee*e" : 
         approach : p first char is * or other :   
         if * is at begining ,  check for remaing Plength == and Slength and char compare if all matches then true:
    if * present in middle of some where : 
          now before * startBeforeSubstring , startAfterSubstring : 
              string matching : 
           if  * is at end and Pptr reaching to till * true : 
        */
    }
};