class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), operations = 0;
         for (int i = 0; i <= n - 3; i++) { 
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                operations++;
            }
        }
        return (nums[n - 1] == 1 && nums[n - 2] == 1) ? operations : -1;
              
        /*
       [0,1,1,1,0,0]
        1 0 0 
          1 1 0 
              1 1 1 
         obser :  if nums[currenti] == 1 
                      continue; 

        [0,1,1,1]
         1 0 0 
           1 1 0

        */
    }
};