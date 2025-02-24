class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int rows = mat.size(), columns = mat[0].size();
        vector<tuple<int, int, int>> cells;
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                cells.emplace_back(mat[row][column], row, column);
            }
        }
        sort(cells.begin(), cells.end());

        vector<int> rowMax(rows, 0), colMax(columns, 0);
        vector<int> tempDP(cells.size(), 0);

        for (size_t i = 0; i < cells.size(); ) {
            int j = i;

            while (j < cells.size() && get<0>(cells[j]) == get<0>(cells[i])) {
                auto [val, row, column] = cells[j];
                tempDP[j] = 1 + max(rowMax[row], colMax[column]);  // Transition
                ++j;
            }

            for (size_t k = i; k < j; ++k) {
                auto [val, row, column] = cells[k];
                rowMax[row] = max(rowMax[row], tempDP[k]);
                colMax[column] = max(colMax[column], tempDP[k]);
            }

            i = j;  
        }

        return *max_element(tempDP.begin(), tempDP.end());

          
        
        /*
        [3,1]
        [3,4] :



 [3,1,6]
 [-9,5,7] :
  3 : 
   explore it's right cell : 
    if(ce < dcell) {  3 < 1 false : still i move with that 1 : and explre 
      
       now evertime i have save the beging value  or condtionpn meet value :
         3 < 1 : 
             1 < 6 : which is incorrect :

          3 < 1 : 
              3  < 6
                   6 < 7 :
       if(ce < dcell){
        ans++;
        lastMaxValue = dcell;
       } else {
       }
     DFS(newcell,); 
     }
   1+6+7 = 14 : 

   skip possible ...? if Ccell  < Dcell :
                          ans++;
                       else  move for next cell : 
                        it was not asked conttigeous : just aske donly row , column: 
          optimzed is like :   if i reached 6 : basically at that cell in Dp i have saved :  started with 6 hoe many elemnts are greater i can get : 
                       6    so at 6 cell  in DP  i will store 2 :   
                       7
        
        
         tc : O(n*m) : 
         sc : O(n*m) : 
         what are defauot values i have to store in dp : 
            INT_MIN : 
                 // or -1 : since  single elemt it self increintg or decrsing order :even 0 works:
       
           
        */
    }
};