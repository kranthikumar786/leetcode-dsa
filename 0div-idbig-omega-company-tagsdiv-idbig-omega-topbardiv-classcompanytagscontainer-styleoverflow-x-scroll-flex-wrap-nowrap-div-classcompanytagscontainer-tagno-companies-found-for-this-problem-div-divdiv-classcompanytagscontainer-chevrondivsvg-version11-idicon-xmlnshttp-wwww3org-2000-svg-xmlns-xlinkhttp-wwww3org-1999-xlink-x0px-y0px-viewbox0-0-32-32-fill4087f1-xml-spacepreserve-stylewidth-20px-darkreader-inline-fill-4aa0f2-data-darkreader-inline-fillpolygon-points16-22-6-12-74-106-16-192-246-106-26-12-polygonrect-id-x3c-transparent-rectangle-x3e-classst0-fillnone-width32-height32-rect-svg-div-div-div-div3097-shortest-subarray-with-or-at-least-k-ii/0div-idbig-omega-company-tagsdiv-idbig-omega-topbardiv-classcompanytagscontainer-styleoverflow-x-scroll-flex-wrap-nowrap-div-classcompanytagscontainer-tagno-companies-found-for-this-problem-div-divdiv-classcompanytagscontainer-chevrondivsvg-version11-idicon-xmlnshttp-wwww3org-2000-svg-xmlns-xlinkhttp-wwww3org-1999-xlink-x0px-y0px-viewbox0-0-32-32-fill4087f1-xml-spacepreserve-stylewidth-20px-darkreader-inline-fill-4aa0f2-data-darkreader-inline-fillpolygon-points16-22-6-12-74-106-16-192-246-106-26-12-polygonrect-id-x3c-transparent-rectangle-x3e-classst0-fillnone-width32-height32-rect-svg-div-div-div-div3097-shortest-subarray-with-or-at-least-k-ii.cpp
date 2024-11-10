class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> OR(32,0);
        int Or = 0 , ans = 1e9 , n = nums.size();

        for(int left = 0 , right = 0; right < n; ++right) {
            Or = Or | nums[right];

            for(int i = 0; i < 31; ++i){
                if(!(nums[right] & (1 << i))) continue;
                else OR[i]++;
            }

            if(Or >= k) {
               while(Or >= k && left <= right) {
                   for(int i = 0; i < 31; ++i){
                        if(!(nums[left] & (1 << i))) continue;
                        else OR[i]--;

                        if(!OR[i]) Or = Or ^ (1 << i);
                    }
                    ans = min(ans , right-left+1);
                    left++;
               }
            }
        }

        return (ans==1e9)?-1:ans;
    }
};