class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       //vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>ans(nums.begin(),nums.end());
        /*int  n = nums.size();
         for(int i = 0 ; i < n ;i++) {
             for(int j = i ; j <  n;j++) {
                   if( nums[j] < nums[i]) 
                       swap(nums[j],nums[i]);
             }
         }
        return nums;
        */
         int i = 0 ;
         while (ans.size()) {
             
              cout<<ans.top()<<" ";
              nums[i++] = ans.top();
                 ans.pop();
         }
         return nums;
    }
};