class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
     map<int,int>mp;
      
     for(int val  :nums){
         mp[val]++;
     }
    
      for (int i = 1 ; i <= nums.size()+1 ; i++ ) {
          
           if(mp.find(i) == mp.end()) {
               return i;
           }
          
      }  
     return 1;   
        
        
  /*
        
        
        set<int>Myset;
         int maxVal = 0;  
       for(int val : nums) {
            Myset.insert(val);
          maxVal = max(maxVal,val);
        }
        
       for(int i =  1 ; i <= maxVal; i++) {
           if(Myset.find(i) == Myset.end()) {
                 return i;
           }
       } 
       return maxVal+1; 
       */
        //for(int i)
        
        
        
        /*
      int n = nums.size();
        
         int i  = 0 ;
           while( i < n) {
                   
             //     values      1 2 3 4 5 6    maxelement 6 
               //   index = >   0 1 2 3 4 5    size = 6 and index is 5 
                    
                     
                    //  for 6 we don't have index so we have to be careful while dealing with it  
                    
               if(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]){
                  swap(nums[i] , nums[nums[i] - 1]);
               }
                else {i++;}
           }
       
        for(int i = 0 ; i< n ;i++) {
            
            if(nums[i] != (i + 1))
                 return i+1;
        }
        
     return n + 1 ;   
        */
        
        
        
        /*
        
        1 3 3 4 5 
        
        0 1 2 3 4
        
        
        
        
        
        */
        
        
        
        /*
        unordered_map<int,int>Frequency;
       for(int index = 0 ; index < nums.size() ; index++) {
           Frequency[nums[index]]++;
       }
     
        for(int i = 1 ; i <= nums.size()+1 ;i++) {
             if( Frequency.count(i) == 0 ){ 
                 return i ;
             }
        }
     return 1;
     */
        
        
        /*sort(nums.begin(),nums.end());
        int smallestMissingPositive  = 1 , k = 1;
        for(auto x:nums){
            if(x < smallestMissingPositive ) 
                continue;
            else if( x == smallestMissingPositive) {smallestMissingPositive++;}
            else if(x - smallestMissingPositive > 1 ) {
               // cout<<smallestMissingPositive<<"\n"; 
                return smallestMissingPositive;
            }
            
        }
        return smallestMissingPositive;
        */
    
      /*  
        for (int indexi = 0 ;indexi < n ; indexi++) {
            
              if(nums[indexi] <=0 )
                    continue;
            
              bool  hasFound  = 0;
            for (int indexj = 0 ; indexj < n; indexj++) {
                
                 if(nums[indexj] == smallestMissingPositive) {
                     hasFound = 1;    
                     break;
                 }
            }
            
            if(hasFound){
                smallestMissingPositive++;
            } else{
                return smallestMissingPositive;
            }
            
        }
     return smallestMissingPositive;;
     */
    }
};


/*
n*n
Nlogn
n ; N = > hash
n  : n = > set 

 n : 1 = >using index as peropert
 n : 1 =  >using module operator 
 n : 1 =  >any othe ways ..? 
 
 
 why not able to apply cyclic sort on this porblem .. ? becuase of -ve values .. ? 
 
   or what ..? 
   
   
 

*/

/*
  int i = 0;
  int n = nums.size();
  while (i < n)
  {
      if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
          swap(nums[i], nums[nums[i]-1]);
      else
          i++;
  }
  for (i = 0; i < n; ++i)
      if (nums[i] != (i+1))
          return i+1;
  return n+1;



 



/*


use break condtion for this kind of probelm like searching scenario , 
n*n
Nlogn
n ; N = > hash
n  : n = > set 

 n : 1 = >using index as peropert
 n : 1 =  >using module operator 
 n : 1 =  >any othe ways ..? 
 
 
 why not able to apply cyclic sort on this porblem .. ? becuase of -ve values .. ? 
 
   or what ..? 
   
   








======================================================================================================

   class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    
          int smallestMissingPositive  = 1;
        int n = nums.size();
        for (int indexi = 0 ;indexi < n ; indexi++) {
            
              if(nums[indexi] <=0 )
                    continue;
            
              bool  hasFound  = 0;
            for (int indexj = 0 ; indexj < n; indexj++) {
                
                 if(nums[indexj] == smallestMissingPositive) {
                     hasFound = 1;    
                     break;
                 }
            }
            
            if(hasFound){
                smallestMissingPositive++;
            } else{
                return smallestMissingPositive;
            }
            
        }
     return smallestMissingPositive;;
    }
};

=============================================================================================================
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    
        sort(nums.begin(),nums.end());
        int smallestMissingPositive  = 1 , k = 1;
        for(auto x:nums){
            if(x < smallestMissingPositive ) 
                continue;
            else if( x == smallestMissingPositive) {smallestMissingPositive++;}
            else if(x - smallestMissingPositive > 1 ) {
               // cout<<smallestMissingPositive<<"\n"; 
                return smallestMissingPositive;
            }
            
        }
        return smallestMissingPositive;
    
}};

added last  elseif for best time complexity 
 [-1, -1, 1, 1, 3,4,5,6,7,8,9,10,11,12,13,14,15]

 no need to come till end simply return after processing index 4 
 ============================================================================

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

  unordered_map<int,int>Frequency;
       for(int index = 0 ; index < nums.size() ; index++) {
           Frequency[nums[index]]++;
       }
     
        for(int i = 1 ; i <= nums.size()+1 ;i++) {
             if( Frequency.count(i) == 0 ){ 
                 return i ;
             }
        }
     return 1;

}};

=====================================================

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {


int n = nums.size();
        
         int i  = 0 ;
           while( i < n) {
                   
             //     values      1 2 3 4 5 6    maxelement 6 
               //   index = >   0 1 2 3 4 5    size = 6 and index is 5 
                    
                     
                    //  for 6 we don't have index so we have to be careful while dealing with it  
                    
               if(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]){
                  swap(nums[i] , nums[nums[i] - 1]);
               }
                else {i++;}
           }
       
        for(int i = 0 ; i< n ;i++) {
            
            if(nums[i] != (i + 1))
                 return i+1;
        }
        
     return n + 1 ;   
}
      };



 [-1, -1, 1, 1, 3,4,5,6,7,8,9, 10,11,12,13,14,15]
  0  1    2  3  4 5 6 7 8 9 10 11 12 13 14 15 16  


[1, 1, 1, 1, 3,4,5,6,7,8,9, 10,11,12,13,14,15]
 
  ==============================================================================

  C++ || 5 ways  || Sorting || searching || unorderd_map || ArrayModification 

use map / set / unrdereserdset 
use module operator method


  TimeLimit : 
*/