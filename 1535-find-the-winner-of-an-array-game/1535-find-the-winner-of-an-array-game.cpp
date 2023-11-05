class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
  
    int currentWinner = arr[0];
    int count = 0;
    int n = arr.size();
    for (int i = 1 ; i < n; i++ ){
         if(arr[i] > currentWinner) {
              currentWinner = arr[i];
               count = 1;
         } else {count++;}

         if ( count == k) {
              return currentWinner;
         }
    }
    return currentWinner;
    }
};

    /*
       Basic Idea Is : 
          


        check   max1 =max(arr[0],arr[1])
         


  
          and 

          add min elemnet at end of array 

          and place max value at 0 th position 
  
       repeate this action till array wincount ==2 , don't give condition of array size , since beofre reaching the end of elemetns ,we may get ans.
        
     deque also coming 
    
      */ 