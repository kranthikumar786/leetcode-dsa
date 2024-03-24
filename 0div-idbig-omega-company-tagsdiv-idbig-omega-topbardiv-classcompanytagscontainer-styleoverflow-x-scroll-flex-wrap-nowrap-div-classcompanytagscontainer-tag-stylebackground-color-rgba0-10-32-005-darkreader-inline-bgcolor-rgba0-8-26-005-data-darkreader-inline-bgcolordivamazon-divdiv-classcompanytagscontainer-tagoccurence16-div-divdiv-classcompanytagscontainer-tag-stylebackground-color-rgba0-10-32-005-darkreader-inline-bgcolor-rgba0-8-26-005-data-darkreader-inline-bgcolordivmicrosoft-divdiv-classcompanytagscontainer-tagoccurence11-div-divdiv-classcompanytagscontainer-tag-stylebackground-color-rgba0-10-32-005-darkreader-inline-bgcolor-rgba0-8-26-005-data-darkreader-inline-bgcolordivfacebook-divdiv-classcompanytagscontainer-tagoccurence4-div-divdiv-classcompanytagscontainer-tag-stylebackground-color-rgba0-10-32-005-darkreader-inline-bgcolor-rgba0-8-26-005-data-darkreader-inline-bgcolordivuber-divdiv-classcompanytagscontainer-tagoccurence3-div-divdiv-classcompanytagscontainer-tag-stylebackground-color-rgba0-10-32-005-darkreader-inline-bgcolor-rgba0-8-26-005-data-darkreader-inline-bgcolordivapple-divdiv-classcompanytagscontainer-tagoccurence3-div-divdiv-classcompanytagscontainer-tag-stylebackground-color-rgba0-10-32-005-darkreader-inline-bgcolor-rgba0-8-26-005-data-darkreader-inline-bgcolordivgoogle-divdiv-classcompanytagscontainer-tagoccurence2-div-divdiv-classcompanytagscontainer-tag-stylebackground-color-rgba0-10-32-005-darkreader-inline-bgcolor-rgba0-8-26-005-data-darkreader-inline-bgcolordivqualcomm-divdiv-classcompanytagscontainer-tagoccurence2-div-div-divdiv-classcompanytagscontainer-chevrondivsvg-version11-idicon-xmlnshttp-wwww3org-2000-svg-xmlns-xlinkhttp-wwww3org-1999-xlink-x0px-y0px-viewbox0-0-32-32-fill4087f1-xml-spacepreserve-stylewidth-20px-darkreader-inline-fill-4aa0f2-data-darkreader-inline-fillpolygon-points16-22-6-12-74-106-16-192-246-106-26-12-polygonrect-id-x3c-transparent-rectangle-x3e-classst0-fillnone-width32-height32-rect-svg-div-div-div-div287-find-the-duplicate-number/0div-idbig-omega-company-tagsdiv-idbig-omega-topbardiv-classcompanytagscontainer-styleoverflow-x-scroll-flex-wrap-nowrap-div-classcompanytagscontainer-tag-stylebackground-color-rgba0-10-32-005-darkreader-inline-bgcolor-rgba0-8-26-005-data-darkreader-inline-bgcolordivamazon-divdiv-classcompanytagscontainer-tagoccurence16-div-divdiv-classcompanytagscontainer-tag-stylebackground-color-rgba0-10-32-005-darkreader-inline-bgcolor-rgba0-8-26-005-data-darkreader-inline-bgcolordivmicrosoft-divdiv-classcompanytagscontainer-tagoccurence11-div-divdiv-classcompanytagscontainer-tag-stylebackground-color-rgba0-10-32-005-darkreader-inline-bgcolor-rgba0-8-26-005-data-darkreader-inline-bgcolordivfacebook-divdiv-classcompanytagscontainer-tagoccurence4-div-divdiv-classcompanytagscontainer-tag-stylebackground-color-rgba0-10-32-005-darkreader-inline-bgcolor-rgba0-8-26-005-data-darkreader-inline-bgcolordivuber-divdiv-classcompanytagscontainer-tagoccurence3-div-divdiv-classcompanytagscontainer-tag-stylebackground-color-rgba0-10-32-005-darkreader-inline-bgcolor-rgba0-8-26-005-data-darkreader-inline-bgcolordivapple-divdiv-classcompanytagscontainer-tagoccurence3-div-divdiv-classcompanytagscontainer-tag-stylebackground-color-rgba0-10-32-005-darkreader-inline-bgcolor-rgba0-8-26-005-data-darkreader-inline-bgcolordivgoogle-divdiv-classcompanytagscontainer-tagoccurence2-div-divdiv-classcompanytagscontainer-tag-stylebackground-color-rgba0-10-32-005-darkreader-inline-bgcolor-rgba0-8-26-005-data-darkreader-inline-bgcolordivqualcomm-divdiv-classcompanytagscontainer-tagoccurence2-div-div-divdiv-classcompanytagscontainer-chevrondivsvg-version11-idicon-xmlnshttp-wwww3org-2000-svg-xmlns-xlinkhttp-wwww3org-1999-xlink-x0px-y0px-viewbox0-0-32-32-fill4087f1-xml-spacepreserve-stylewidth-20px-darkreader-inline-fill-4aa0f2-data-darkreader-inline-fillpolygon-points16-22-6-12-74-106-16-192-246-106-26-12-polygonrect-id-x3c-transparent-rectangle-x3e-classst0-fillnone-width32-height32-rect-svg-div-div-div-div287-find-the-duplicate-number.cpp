class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int>S;
        for(int i = 0 ; i < n ; i++) {
            if(S.find(nums[i]) != S.end()){
                 return nums[i];
            }else{
                S.insert(nums[i]);
            }
        }
  return 0;
    }
};