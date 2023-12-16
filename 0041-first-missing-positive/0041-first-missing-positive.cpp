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