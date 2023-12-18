class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
   int n = nums.size();
     int  Mod =1e9+7;
   long Prod = 1;
    long p1 = ((long)nums[0] * nums[1])%Mod;
     long p2 = ((long)nums[n-1] * nums[n-2])%Mod;
     Prod =  (p2 - p1)%Mod;
  return Prod;
    }
};