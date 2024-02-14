class Solution {
public:
    int maximumChocolates(int totalRows, int totalColumns, int currentRow,
                          int robotACurrentColumnIndex, int robotBCurrentColumnIndex,
                          vector<vector<int>> &grid,vector<vector<vector<int>>>&DP) {
    
       
if ( robotACurrentColumnIndex < 0 || robotACurrentColumnIndex >= totalColumns || 
     robotBCurrentColumnIndex < 0 || robotBCurrentColumnIndex >= totalColumns ) {
            return -1e8;
        }
        
        
      if(DP[currentRow][robotACurrentColumnIndex][robotBCurrentColumnIndex] != -1) {
             return DP[currentRow][robotACurrentColumnIndex][robotBCurrentColumnIndex];
      }  
        
      if ( currentRow == totalRows - 1 ) {
          if ( robotACurrentColumnIndex == robotBCurrentColumnIndex ) {
                 return  grid[currentRow][robotACurrentColumnIndex];
          } else {
             return  grid[currentRow][robotACurrentColumnIndex] 
                   + grid[currentRow][robotBCurrentColumnIndex];
          }   
      }  
        //int maxforRow = 0;
        for(int robotAPlaces = -1 ;robotAPlaces <= 1; robotAPlaces += 1 )  {
            for(int robotBPlaces = -1 ; robotBPlaces <= 1 ; robotBPlaces += 1 ){
                    
                 int value = 0;
                if(robotACurrentColumnIndex == robotBCurrentColumnIndex ) {
                        
                       value = grid[currentRow][robotACurrentColumnIndex];
                    } else {
                        value = grid[currentRow][robotACurrentColumnIndex] + grid[currentRow][robotBCurrentColumnIndex]; 
                    }
               value += maximumChocolates(totalRows,totalColumns,currentRow + 1 , 
                                      robotACurrentColumnIndex + robotAPlaces ,
                                        robotBCurrentColumnIndex + robotBPlaces,grid,DP); 
            DP[currentRow][robotACurrentColumnIndex][robotBCurrentColumnIndex] = max(value, DP[currentRow][robotACurrentColumnIndex][robotBCurrentColumnIndex]);
            }
        }
         return  DP[currentRow][robotACurrentColumnIndex][robotBCurrentColumnIndex];
    }    
    int cherryPickup(vector<vector<int>>& grid) {
         int totalRows  = grid.size(); 
         int totalColumns = grid[0].size();         
vector<vector<vector<int>>>DP(totalRows, vector<vector<int>>(totalColumns,vector<int>(totalColumns,-1)));
        return maximumChocolates(totalRows,totalColumns,0,0,totalColumns-1,grid,DP);

    }
};

/*

Complexity Analysis : 

Time Complexity : 


*/
