class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();
    if(n < 3 ) {return 0;}
    long long  leftMax = nums[0];
    long long  rightMax = 0;   
       for(int i = 1; i < n -1; i++) {          
            rightMax = max(rightMax, leftMax - nums[i]); 
            ans = max(ans, rightMax * nums[i + 1]);    
           leftMax = max(leftMax, (long long)nums[i]);  
        }
         return ans <= 0 ? 0 :ans; 
    }
};