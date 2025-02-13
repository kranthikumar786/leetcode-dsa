class Solution {
    public int halveArray(int[] nums) {
      PriorityQueue<Double> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        double sum = 0.0;
       for(int num : nums){
          sum += num;
        maxHeap.add((double)num);
       } 
       double sum2 = sum;
       sum /= 2.0;
      int minOperations = 0;
       while(maxHeap.size() > 0 && sum < sum2 ) {
            minOperations++;
            double topV = maxHeap.poll();
            sum2 -= topV;
            topV /= 2.0;
           sum2 += topV; 
         maxHeap.add(topV);  
       } 
      return minOperations; 
    }
}