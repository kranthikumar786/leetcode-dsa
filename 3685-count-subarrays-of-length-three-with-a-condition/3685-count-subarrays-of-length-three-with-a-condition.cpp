class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
         for(int i = 0 ;i <= n-3; i++) {
             int sum = nums[i] + nums[i+2];
             if(sum*2 == nums[i+1]){
                ans++;
             } 
         }
        return ans; 
    }
};
/*


[10,0,-10]
 0  1  2 

0 == 0 /2 
0 == 0 : 

[-1,-4,-1,4]
 0  1  2   3 

-2 == -4/2: 
-2 == -2 : 

0 == -1/2

    -1/2 =
    1 

 

[1,2,1,4,1]
 0 1 2 3 4 
 5-3 = 2
 0 1 2  : 

*/