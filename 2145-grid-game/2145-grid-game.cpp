class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
    long long firstRowSum = accumulate(begin(grid[0]),end(grid[0]),0LL),secondRowSum = 0;
    long long minimumSum = LONG_LONG_MAX;
    for(int  turnIndex = 0 ; turnIndex < grid[0].size();turnIndex++) {
        firstRowSum -= grid[0][turnIndex];
        minimumSum = min(minimumSum, max(firstRowSum, secondRowSum));
        secondRowSum += grid[1][turnIndex];
    }
    return minimumSum;
  }
};
      /*
      
       local max taking might be not correct approch : 
        like : 
           here local referrirng neighbour : 
              in blue : 
                0 0 
                1 
       if it chose to go with down , we may not get the max ans  : 
        so : 
           try with all possiblity of existing then : get max out it it : 
 

        do compution from down right  to top left for second robot : 
         
          for first robot : 
           come from top left to bottom right: 

 fun(r,c,col){
     if(inRange(r,c,cols)) {
             sum + = grid[r][c] ;
              fun(r+1,c) ;
             fun(r,c+1);
             sum -= grid[r][c]; 
        9  = 2 + 1 + 5 + 1   : 
            8 :
         --------------
         2 + 5 + 5  + 1 = 13 :  max : 
     now i wanted to mark this path with zeros : 
     but in future how iam sure that i won't get max ...? 
       so changes to zeros here it self won't work : 
     or let's have corrindtares store the paths: 
       by max values : 
  later update ..? 
  but how ..? 
  

 which mean si have to be aware of it before hand : what path give max : 
 so tht path i jave make zeros : 


    }
}
      */  


        /*
        */
    