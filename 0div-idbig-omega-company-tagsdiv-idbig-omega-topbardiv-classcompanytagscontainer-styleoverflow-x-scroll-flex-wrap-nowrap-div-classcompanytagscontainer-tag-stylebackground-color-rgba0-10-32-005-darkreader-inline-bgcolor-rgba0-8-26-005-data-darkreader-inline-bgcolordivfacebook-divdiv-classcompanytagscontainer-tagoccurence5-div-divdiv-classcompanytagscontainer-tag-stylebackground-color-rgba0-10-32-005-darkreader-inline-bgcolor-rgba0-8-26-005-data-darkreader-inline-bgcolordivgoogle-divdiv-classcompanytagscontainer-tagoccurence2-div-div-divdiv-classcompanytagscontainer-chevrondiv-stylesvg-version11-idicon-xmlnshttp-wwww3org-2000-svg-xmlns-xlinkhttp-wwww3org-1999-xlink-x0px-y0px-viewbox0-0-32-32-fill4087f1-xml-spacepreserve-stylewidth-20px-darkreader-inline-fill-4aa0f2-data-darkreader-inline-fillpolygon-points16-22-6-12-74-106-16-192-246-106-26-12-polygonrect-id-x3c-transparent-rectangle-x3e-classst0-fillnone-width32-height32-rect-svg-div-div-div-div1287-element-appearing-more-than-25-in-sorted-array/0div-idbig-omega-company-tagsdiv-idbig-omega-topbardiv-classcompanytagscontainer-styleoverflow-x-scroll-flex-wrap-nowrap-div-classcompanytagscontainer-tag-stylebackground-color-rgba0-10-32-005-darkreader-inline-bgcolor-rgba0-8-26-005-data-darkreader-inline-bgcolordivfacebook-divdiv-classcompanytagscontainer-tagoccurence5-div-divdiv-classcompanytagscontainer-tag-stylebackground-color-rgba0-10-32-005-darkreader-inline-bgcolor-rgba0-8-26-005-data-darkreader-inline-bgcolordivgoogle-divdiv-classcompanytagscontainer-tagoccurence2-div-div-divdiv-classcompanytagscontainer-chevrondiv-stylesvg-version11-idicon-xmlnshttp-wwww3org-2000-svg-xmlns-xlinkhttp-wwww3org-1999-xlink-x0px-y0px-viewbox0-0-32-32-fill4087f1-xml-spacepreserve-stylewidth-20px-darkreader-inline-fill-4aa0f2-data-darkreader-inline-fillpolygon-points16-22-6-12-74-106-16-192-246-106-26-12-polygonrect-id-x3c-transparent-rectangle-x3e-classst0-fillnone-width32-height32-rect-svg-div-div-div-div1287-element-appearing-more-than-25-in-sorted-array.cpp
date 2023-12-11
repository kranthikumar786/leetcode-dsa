class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
   
        /*
     1.   
        count of an element > n/4 then return that value since it is only single value exist in array.
        
        TC: O(n*n)
        Sc:O(1)
        
    2.using frequency arrray  :
     count of an element > n/4  then return ans;
     TC: O(n)
     SC:O(N)
       
     3. array is sorteed and we need to check an space of subarray or contigeous apce which is        having element > n/4 
      then return that element , 
      since only one number exist so no need to travels entire array 
       after found eleemnet  we can break ;
     */
        
     int n = arr.size() ,size = n / 4;
        
        for(int i = 0 ; i < arr.size() - size ;i++ ) {
         if(arr[i] == arr[i+size]) {
              return arr[i];
         }   
    }  
     
        return -1;
    }
};