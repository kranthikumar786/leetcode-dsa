class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int i = 0;
        vector<int> grps;
        while(i<nums.size()){
            int i1 = i;
            int p1 = __builtin_popcount(nums[i]);
            int mx = INT_MIN;
            int mn = INT_MAX;
            while(i<nums.size() && p1 == __builtin_popcount(nums[i])) {
                mx = max(mx,nums[i]);
                mn = min(mn,nums[i]);
                i++;
            }
            grps.push_back(mn);
            grps.push_back(mx);

        }
        if(is_sorted(grps.begin(),grps.end())) return true;
        return false;
    }
};