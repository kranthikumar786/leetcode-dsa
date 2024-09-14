class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int  movingPtr = 0 , right = n-1;
        int maxValue = *max_element(nums.begin(),nums.end());
        int maxLength = 0; int localMaxLength = 0;      
           for(int num : nums) {
              if(maxValue == num){
                localMaxLength++;
              } else {
                  maxLength = max(maxLength, localMaxLength);
                localMaxLength = 0;
              }
           }
  return max(maxLength,localMaxLength); 
    }
};
/*[1,1,1,1,2,2,2,1,1,1,1,1] O/p : 3 */
/*[1] - 1*/
/*[1,1,1,1,1,1,1,1,1] - 9 */
/*[1,1,2,2,2,2] - 4*/
/*[2,2,2,2,1,1,1] - 4*/
