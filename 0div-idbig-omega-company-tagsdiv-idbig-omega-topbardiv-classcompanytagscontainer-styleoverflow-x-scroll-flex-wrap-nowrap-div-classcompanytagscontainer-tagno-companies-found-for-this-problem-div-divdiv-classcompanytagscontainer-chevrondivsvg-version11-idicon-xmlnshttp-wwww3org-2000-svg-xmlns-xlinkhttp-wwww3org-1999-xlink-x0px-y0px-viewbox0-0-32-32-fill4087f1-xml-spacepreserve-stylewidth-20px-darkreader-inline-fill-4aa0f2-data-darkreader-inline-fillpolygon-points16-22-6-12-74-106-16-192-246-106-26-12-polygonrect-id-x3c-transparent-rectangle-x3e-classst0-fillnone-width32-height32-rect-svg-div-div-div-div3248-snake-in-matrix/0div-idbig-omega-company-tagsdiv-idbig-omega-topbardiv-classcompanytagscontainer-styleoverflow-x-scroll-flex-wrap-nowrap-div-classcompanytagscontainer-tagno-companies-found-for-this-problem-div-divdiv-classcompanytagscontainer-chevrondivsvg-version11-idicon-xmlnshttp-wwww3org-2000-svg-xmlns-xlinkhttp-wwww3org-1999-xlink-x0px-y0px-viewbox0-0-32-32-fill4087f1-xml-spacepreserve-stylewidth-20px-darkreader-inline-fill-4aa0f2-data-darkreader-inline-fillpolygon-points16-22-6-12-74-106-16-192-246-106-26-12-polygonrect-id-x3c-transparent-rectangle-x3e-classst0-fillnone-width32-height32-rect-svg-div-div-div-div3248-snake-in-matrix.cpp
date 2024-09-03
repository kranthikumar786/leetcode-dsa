class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
       vector<vector<int>>matrix(n, vector<int>(n,0));
      int k = 0;
     for(int i = 0 ; i < n ;i++) {
          for(int j = 0 ; j < n ;j++) {
                matrix[i][j] = k++;
          }
     }
  int j=0;k=0; int ans = 0;
      for(int i = 0 ; i < commands.size() ; i++) {
            string s = commands[i];
             if(s[0] == 'D') {
                ++j;
             } else if (s[0] == 'R') {
                ++k;
             } else if(s[0] == 'U') {
                   --j;
              }else {--k;}
      }
      return matrix[j][k];
    }
};