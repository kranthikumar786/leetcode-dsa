class Solution {
public:


vector<vector<string>>ans;
vector<string>paths;

 bool isPalindrome(string s , int leftIndex , int rightIndex) {
          while( leftIndex <= rightIndex ) {
                  if(s[leftIndex] != s[rightIndex]) {
                        return false;
                  }
              leftIndex++ ;
              rightIndex--;
          }
          return 1 ;
 }

void Helper(int index, const string &s ) {
    if(index == s.size()) {
        ans.push_back(paths);
         return;
    }
  for(int i = index ; i < s.size() ; i++) {
      if( i== index || isPalindrome(s, index, i)) {
          paths.push_back(s.substr(index, i - index +1));
          Helper(i +1 , s );
          paths.pop_back();   
      }
  }
    return;
}
    vector<vector<string>> partition(string s) {
        Helper(0,s);
        return ans;
    }
};