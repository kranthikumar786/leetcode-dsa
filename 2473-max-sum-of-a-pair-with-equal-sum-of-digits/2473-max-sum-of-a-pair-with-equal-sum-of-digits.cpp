class Solution {
public:
    void calculateDigitSum(const vector<int>& nums, vector<int>& pre) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int number = nums[i], sum = 0;
            while (number > 0) {
                sum += (number % 10);
                number /= 10;
            }
            pre[i] = sum;
        }
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0);
        calculateDigitSum(nums, pre);
        unordered_map<int, vector<int>> digitSumBasedMap;
        int maxSum = -1;
        for (int i = 0; i < n; i++) {
            int digitSum = pre[i];
            if (digitSumBasedMap.count(digitSum)) {
                auto& p = digitSumBasedMap[digitSum]; 
                int num1 = nums[p[0]];
                int num2 = (p[1] == -1) ? INT_MIN : nums[p[1]];
                int current = nums[i];
                if (current > num1) { 
                    p[1] = p[0]; 
                    p[0] = i;
                } else if (current > num2) { 
                    p[1] = i;
                }
                if (p[1] != -1) {
                    maxSum = max(maxSum, nums[p[0]] + nums[p[1]]);
                }
            } else {
                digitSumBasedMap[digitSum] = {i, -1};
            }
        }
        return maxSum;
    }
};
