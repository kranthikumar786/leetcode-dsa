class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
    //      int pos = 0, neg = 0;
    //     for(int num : nums){
    //             neg += num < 0 ;
    //             pos += num > 0; 
    //     }
    //    return max(pos,neg); 
        // Find the first index of a non-negative number
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        // Find the first index of a positive number
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        
        return max(neg, pos);
    }
};
