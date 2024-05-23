class Solution {
public:
    void backtrack(vector<int>& nums, int k, int ind, map<int, int>& freq, int& res) {
        if (ind == nums.size()) {
            res++;
            return;
        }
        backtrack(nums, k, ind + 1, freq, res);
        int curNum = nums[ind];
        if (!freq[curNum - k]) {
            freq[curNum]++;
            backtrack(nums, k, ind + 1, freq, res);
            freq[curNum]--;
        }
            
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int res = 0;
        map<int, int> freq;
        backtrack(nums, k, 0, freq, res);
        return res - 1; 
    }
};