class Solution {
public:
   bool isValid(int newX,int newY, int rows,int columns){
       return (newX >= 0 && newX  < rows && newY >= 0 && newY < columns);
   }
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
         vector<vector<int>> visited(rows, vector<int>(columns, 0));
       queue<pair<int,int>>Q;
        int ans = 0;
    for(int row = 0 ; row < rows ; row++) {
          for(int column = 0 ; column < columns ; column++){
               if(grid[row][column] && !visited[row][column]){
                 visited[row][column] = 1;
                  Q.push({row,column});   
                   int val = 0; 
                    while(Q.size() > 0 ) {   
                       auto v = Q.front();
                       val += grid[v.first][v.second];
                       Q.pop();
                       int arr[4][4] = {{0,1},{0,-1},{1,0},{-1,0}};
                      for(int i = 0 ; i < 4; i++) {
                         int newX = v.first + arr[i][0];
                         int newY = v.second + arr[i][1];    
                            if(isValid(newX,newY, rows,columns) && grid[newX][newY] && !visited[newX][newY]) {
                                Q.push({newX,newY});
                                visited[newX][newY] = 1;
                            } 
                      }
                    }
                    ans = max(ans, val);
               }   
          }}
          return ans;
          }
    };
        /*
     start with (0,0) : since it is land : so move to right :  collect 2 +1 = 3 : till now max is 3 : 
      and all adjeacent for this is 0 so : move ahaed :
       where land prenesent : 
       4 - > 0 : 
       4- >1 = 5 : now max updated to 5 :  visited mark : 
       0 -> 0 > 0 > 

        now 3 : 3 + 4 = 7 : max till now : is 7 with latest update 


        next row : 
         1 already visited or taken so skip it : 
         0 , 0 ,0, : 4 visited :

         0 , 3 + 2 = 5 : 0 : 
         now Que become empty:
         so return finalAns:
         max from the continuous  edge values : 
        
     }
 };
 */