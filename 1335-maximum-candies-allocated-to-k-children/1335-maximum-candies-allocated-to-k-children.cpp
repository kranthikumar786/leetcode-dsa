class Solution {
public:

    bool canCan(vector<int>&candies, long long k, int numOfCandies){
        long long maxNumOfChildren = 0;
              for(int candie : candies) {
                maxNumOfChildren += (candie/numOfCandies);
              }
              return maxNumOfChildren >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
       int maxCandie = 0 ;
       for(int candie : candies) {
          maxCandie = max(maxCandie,candie);
       }
       int left = 0; 
       int right = maxCandie;
      while(left < right) {
        int middle = (right + left+1)/2;
        if(canCan(candies,k,middle)){
            left = middle;
        }else{
           right = middle -1;
        } 
      } 
  return left;

//       int minValue = INT_MAX;
//       for(int candie : candies) {
//         minValue = min(candie,minValue);
//       }
//     long long  can = 0;
//      for(int candie : candies) {
//            can += (candie/minValue);
//      }
//  return (can == k ? minValue : 0);
     /*     
      C = [5,8,6]  , K = 3: 

            5 + 8 + 6 

    mean don't work becuase i can 't combine : 
    only division is possible : 
    so get minvalue : then get the value of moudle to say how many no .of time that value is present : reminder help to provide : 



    8%5 = ...? 
    8/5 ...? 1 : 


[50,50] k = 11 : 

 k = 11 : 

 50/2 = 25 : 
 50/2 = 25 : 





     */
    }
};