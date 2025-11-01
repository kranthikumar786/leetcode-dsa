class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int minSize = Integer.MAX_VALUE;
        int leftPtr = 0, rightPtr = 0;
        int sum = 0;

        while (rightPtr < n) {
            sum += nums[rightPtr];
            while (sum >= target) {
                minSize = Math.min(minSize, rightPtr - leftPtr + 1);
                sum -= nums[leftPtr];
                leftPtr++;
            }
            rightPtr++;
        }

        return minSize == Integer.MAX_VALUE ? 0 : minSize;
    }
}

/**

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int minSize = Integer.MAX_VALUE;
        int n = nums.length;
        int leftPtr = 0 , rightPtr = 0;
        int sum = 0;
        /**
        1 4  4 

           t = 4: 

        while(rightPtr < n) {
             sum += nums[rightPtr];
               while(sum >= target){
                     minSize = Math.min(minSize,rightPtr-leftPtr+1);  
                    sum -= nums[leftPtr];
                      leftPtr++;
               }
            rightPtr++;
        }
       return   minSize == n ? 0 : minSize;
    }
}
 */