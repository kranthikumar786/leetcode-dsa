class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> oneD;
        int totalRows = grid.size();
        int totalColumns = grid[0].size();

        for (int rowNumber = 0; rowNumber < totalRows; rowNumber++) {
            for (int columnNumber = 0; columnNumber < totalColumns; columnNumber++) {
                oneD.push_back(grid[rowNumber][columnNumber]);
            }
        }

        sort(oneD.begin(), oneD.end());
        int median = oneD[oneD.size() / 2];

        int totalOperations = 0;
        for (int value : oneD) {
            if ((value - median) % x != 0) {
                return -1;
            }
            totalOperations += abs(value - median) / x;
        }

        return totalOperations;
    }
};

// class Solution {
// public:
//     int minOperations(vector<vector<int>>& grid, int x) {

//      vector<int>oneD;
//      int totalRows = grid.size();
//      int totalcolumns = grid[0].size();
//     //  for(int row = 0 ; row < rows ; row++ ) {
//     //       for(int column = 0 ; column < column)
//     //  }

//   for(int rowNumber : totalRows) {
//     for(int columnNumber : totalcolumns) {
//         oneD.push_back(columnNumber); 
//     }
//   }
//   sort(oneD.begin(),oneD.end());

//   int medianOrUniqueValue  = oneD[ondeD.lengt()/2];
//     int totalOpreation = 0 ;
//   for(int value : ondeD){
      
//        if(value % x != 0 && medianOrUniqueValue % x  != 0) {
//                 return -1;
//        }
// totalOpreations +=(value/x);
//   }
// return totalOpreations;



/* 
   0 4 
   8 12
 1 5     x = 4 : 
 9 12  

5 5 
5 5 

   4/2 = 2 :
   4/4 =1 : 
   6%4 = 1 :    
   x = 4: 
 // 12/4 = 3/2 = 1 :  
         BF : 
            conside g[i][j] is unique:  
               
                  check for remianing elemtns like : 
                     if(a[i+1][j+1] > grid[i][j] && a[i+1][j+1] % grid[i][j] == 0) {
                            int add value = (a[i+1][j+1] / grid[i][j])/2;
                            minOpreaiton + =addValue;
                            minoperation += (addValue&1); 
                     }
                     else if( a[i+1][j+1] <  grid[i][j] && a[i+1][j+1] % grid[i][j]   ) {
                          
                minOpreaiton = 0;
                break;
                     }
      return (minOpreaiton == 0 ? -1 : minOpreaiton);    
         if(at any time univalue > current chaningvalue){
                break; 
                 this is not possible:
         }
           if input as even , odd then it is not possbile : 
           x = 1:  is specailc ase here :   so even values inside, odd values values insideis e possible to  make unique :
        x > =2  :   x%2 == 0 :  all values  should be even : 
                    x%2 == 1 : all values should be odd then only  possible to make unique values: 
       x%2 == 1: belowe code won't work : 
         1 3 5 : 
         7 9 11 : 
         x= 3: 
            if every number is dvinginsle by  x , then it gives the resulst:      
        */
//     }
// };