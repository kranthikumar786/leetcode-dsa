class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
       int n = nums.size();
       while (k--) {
          int minIndex = 0;
          for(int i = 1 ; i < n ;i++) {
                 if(nums[minIndex] > nums[i]) {
                    minIndex = i;
                 }
          }
          nums[minIndex] *= multiplier;

       }
  return nums;
    }
};
/*
[2,1,3,5,6]
k
5
M
2
*/