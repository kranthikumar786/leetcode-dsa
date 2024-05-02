class Solution {
public:
    int findMaxK(vector<int>& nums) {
	sort(begin(nums), end(nums));
	int l = 0, r = nums.size() - 1;
	while (l < r) {
		if (nums[l] < 0 && -1*nums[l] == nums[r])
			return nums[r];
		else if (abs(nums[l]) > nums[r])
			l++;
		else
			r--;
	}
	return -1;
}
};