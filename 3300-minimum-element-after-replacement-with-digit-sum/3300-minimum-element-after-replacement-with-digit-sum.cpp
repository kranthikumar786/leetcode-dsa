class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
       int minVal = 10000;
        for(int i = 0 ; i < n ;i++) {
             int sum = 0;
              while(nums[i]) {
                    sum += nums[i]%10;
                     nums[i]/= 10;
              }
             nums[i] = sum;
            minVal = min(nums[i], minVal);
        }
return minVal;
    }
};