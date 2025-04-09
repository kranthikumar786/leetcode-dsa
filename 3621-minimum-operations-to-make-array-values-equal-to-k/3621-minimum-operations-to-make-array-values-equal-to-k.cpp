class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini = *min_element(nums.begin(), nums.end());
        if (mini < k) return -1;

        bool seen[101] = {};
        for (int num : nums) {
            if (num > k) seen[num] = true;
        }

        int count = 0;
        for (int i = k + 1; i <= 100; ++i) {
            if (seen[i]) ++count;
        }

        return count;
    }
};
