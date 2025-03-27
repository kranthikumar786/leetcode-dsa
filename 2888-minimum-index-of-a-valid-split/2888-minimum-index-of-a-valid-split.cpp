class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dominantValue = nums[0], count = 0;
        
        for (int num : nums) {
            if (count == 0) {
                dominantValue = num;
            }
            count += (num == dominantValue) ? 1 : -1;
        }

        int dominantValueFrequency = 0;
        for (int num : nums) {
            if (num == dominantValue) {
                dominantValueFrequency++;
            }
        }

        int leftCount = 0, rightCount = dominantValueFrequency;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominantValue) {
                leftCount++;
                rightCount--;
            }

            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1;
    }
};
