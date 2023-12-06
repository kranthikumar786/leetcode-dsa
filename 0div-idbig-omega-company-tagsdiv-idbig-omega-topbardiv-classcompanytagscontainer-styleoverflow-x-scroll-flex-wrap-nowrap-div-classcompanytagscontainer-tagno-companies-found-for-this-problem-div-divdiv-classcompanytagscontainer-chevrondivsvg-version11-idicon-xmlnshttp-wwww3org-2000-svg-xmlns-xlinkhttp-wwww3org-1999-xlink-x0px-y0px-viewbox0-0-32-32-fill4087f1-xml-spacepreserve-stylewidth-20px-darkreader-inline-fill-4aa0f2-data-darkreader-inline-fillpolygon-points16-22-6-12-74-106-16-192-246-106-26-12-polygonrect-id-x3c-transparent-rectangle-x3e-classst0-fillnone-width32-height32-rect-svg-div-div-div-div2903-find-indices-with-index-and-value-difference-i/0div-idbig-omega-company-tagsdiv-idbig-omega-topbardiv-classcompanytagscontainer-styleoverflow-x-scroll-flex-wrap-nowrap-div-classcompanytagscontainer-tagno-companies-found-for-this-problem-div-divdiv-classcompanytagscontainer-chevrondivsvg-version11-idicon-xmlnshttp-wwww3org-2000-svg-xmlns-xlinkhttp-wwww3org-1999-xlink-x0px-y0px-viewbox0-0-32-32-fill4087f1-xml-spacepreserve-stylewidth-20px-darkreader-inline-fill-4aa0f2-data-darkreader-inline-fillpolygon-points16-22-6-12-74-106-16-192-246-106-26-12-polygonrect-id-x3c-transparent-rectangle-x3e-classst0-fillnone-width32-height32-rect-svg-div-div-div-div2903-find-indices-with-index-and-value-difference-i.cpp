class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n =nums.size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = i; j < n ;j++) {
                
                if(j - i >= indexDifference && abs(nums[j]-nums[i]) >= valueDifference){
                   return {i,j};
                }
            }
        }
         return {-1,-1};     
    }
};