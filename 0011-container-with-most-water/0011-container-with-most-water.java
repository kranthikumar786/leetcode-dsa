class Solution {
    public int maxArea(int[] height) {
      int rightPtr = height.length-1;
      int leftPtr = 0;
      int maxWater = 0;
      while(leftPtr < rightPtr) {
        int minValue = Math.min(height[leftPtr],height[rightPtr]);
        maxWater = Math.max(maxWater, ((rightPtr-leftPtr) * minValue));
       if(height[leftPtr] <= height[rightPtr]) {
        leftPtr++;
       } else{
        rightPtr--;
       }
      }
      return maxWater;
    }
}