class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> UM;
        for (int num : nums) {
            UM[num]++;
        }
        int dominantValue = -1, dominantValueFrequency = -1;
        for (auto itr = UM.begin(); itr != UM.end(); itr++) {
            if (itr->second > dominantValueFrequency) {
                dominantValue = itr->first;
                dominantValueFrequency = itr->second;
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
