class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
       int  n  = arr.size();
       int  target = n/4;
     /*   
        for(int i = 0 ; i < n ; i++) { 
               int count  = 0 ;
            for( int j  = 0 ; j < n ; j++) {
               
                if(arr[i] == arr[j]) {
                      count++;
                }
           }
           if(count > target) {
                 return  arr[i];
           } 
        }
      
        return -1;
        */
        
    
      /*  for(int i = 0 ; i < n ; i++) {
            
            int left =lower_bound(arr.begin(),arr.end(),arr[i])-arr.begin();
            int right = upper_bound(arr.begin(),arr.end(),arr[i])-arr.begin()-1;
            
          
         if(right -left + 1 > target) {
              return arr[i];
         }   
            
        }
        
       return -1; 
        */
      
        unordered_map<int,int>um;
        
        for(int value : arr) {
            um[value]++;
        }
      
        for(auto itr : um){
            
            if(itr.second > target) {
                 return itr.first;
            }
        }
        
        return -1;
        
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
        
      /*
      
      Idea here is not counting and making blocks 
      and 
      checking
      block first element and block last element
      
       
     int n = arr.size() ,size = n / 4;
        
        for(int i = 0 ; i < arr.size() - size ;i++ ) {
         if(arr[i] == arr[i+size]) {
              return arr[i];
         }   
    }  
        return -1;
    
   
     int n = arr.size();
     vector<int>candidates ={arr[n/4] , arr[n/2] , arr[3*n/4]};
       
        int target = n/4;
        
        for(int candidate : candidates) {
            int left = lower_bound(arr.begin(),arr.end(),candidate)-arr.begin();
            int right = upper_bound(arr.begin(),arr.end(),candidate)-arr.begin()-1;
            
            if(right - left + 1 > target) {
                return candidate;
            }
        }
       return -1; 
        */
    }
    
};