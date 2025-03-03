class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     unordered_set<string>setList;
       setList.insert(wordList.begin(),wordList.end());
       queue<pair<string,int>>Q;
       Q.push({beginWord,1});
       setList.erase(beginWord);
       while( !Q.empty() ) {
          string word = Q.front().first;
          int level = Q.front().second;
              Q.pop();
            if(word == endWord) {
                return level ;
            }
             for(int i = 0 ; word[i] ;i++) {
                  char original = word[i];
                   for(char ch = 'a' ; ch <= 'z' ;ch++) {
                            word[i] = ch;
                       if(setList.find(word) != setList.end()){
                           Q.push({word,level+1});
                           setList.erase(word);
                       }  
                   }
                  word[i] = original; 
             }
       }
      return 0;
    }
};