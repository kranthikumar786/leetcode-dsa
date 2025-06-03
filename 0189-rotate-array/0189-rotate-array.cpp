class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int  i = 0 ; 
         int n = nums.size();
        for(int i = 0 ; i < n/2 ; i++){
               swap(nums[i],nums[n-i-1]);
        } 
        
        k = k%n;
       int left = 0 ;
       int right = k-1;
       while(left < right ){
          swap(nums[left],nums[right]);
          left++;
          right--;
       } 
       left = k ;
       right = n-1;
       while(left < right ){
          swap(nums[left],nums[right]);
          left++;
          right--;
       } 

        /*
        [1,2,3,7,5,6,4]

        [1,2,3,4,5,6,7]
         0 1 2 3 4 5 6 

         7 6 5 4 3 2 1 
         5 6 7 1 2 3 4 : 
        */
    }
};