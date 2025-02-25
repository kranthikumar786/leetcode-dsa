class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& A) {
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < j && j < n - 1 - i) {
                    A[i][j] = 0;
                }
                if (j < i && i < n - 1 - j) {
                    A[i][j] = 0;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += A[i][i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                A[i][j] += max({A[i - 1][j - 1], A[i - 1][j], (j + 1 < n) ? A[i - 1][j + 1] : 0});
            }
        }
        for (int j = 1; j < n; ++j) {
            for (int i = j + 1; i < n; ++i) {
                A[i][j] += max({A[i - 1][j - 1], A[i][j - 1], (i + 1 < n) ? A[i + 1][j - 1] : 0});
            }
        }
        return res + A[n - 1][n - 2] + A[n - 2][n - 1];
     /*
      mulptiple users trying to same cell , it should be given to one user :
        
        since we need max :
           user1 : should get max : 
            not  like this ...? 
             only first  one can get it and reaming won't be : 
             update that i,j with zeros or -1:
             

     */   
  
          // neightbour max leads to glable max :as an answer :
 /*
    always chose local  neighourmax to move :
      
      1 + 2 + 3 + 8+7+12 : 
        = di(i + 1, j + 1), 
         di : 1 + 6 + 11  = curremax : 

         
       down (i + 1, j), and  
         1 + 5 + 9 + 10+11 = reached end : 
           max then previous :       
 
         right : (i, j + 1)

                
  if( row == n-1 && column == n-1) {
      return 0;
  }

  if(DP[r][column][d] != 0){
      return DP[r][column][d];

  }
  Recurance Relations  
    how am i sure that it won't taken two times ...? 
     U1 = max({topDownToWardsRightBottomdiagoanl , right, down}
     U2 = max({diagoanl, right,left});
     U3 = max({topDiagonal,rightSide,DownLeftDiagonaldiagonal});
    return DP[row][column][diagoanl] = MAX({U1, U2,U3});
 FROM WHERE IAM STARTING ....? 
   0 ,0  OR 0 ,N-1 OR N-1 ,0   WHERE ...? IAM STARTING ..? 
    WHERE WILL BE THE FINAL ANSWER ...? 
  collect u1 + u2 + u3 : 


 */
    }
};