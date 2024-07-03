class Solution {
public:
    int minDifference(vector<int>& nums) {
      /*int max1 ,max2 ,max3 ;
      int n = nums.size();
      find max1 , max2 ,max3 , max4 and min1 and later max4- min should be ans 
     */
  int n = nums.size();
     if(n <= 4) {return 0;}
     sort(nums.begin(),nums.end());
     int minDiff = INT_MAX;
      for(int i = 0 , j = n - 4 ; i < 4 ; i++,j++ ){
          minDiff = min(minDiff, nums[j]- nums[i]);
      }  
        return minDiff;
    }
};