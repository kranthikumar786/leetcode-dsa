class Solution {
    public int minOperations(int[] nums, int k) {
     PriorityQueue<Integer> minHeap = new PriorityQueue<>();   
     for(int num : nums){
        minHeap.add(num);
     }
     int count = 0 ;
     while (minHeap.peek() < k) {
        int firstMin = minHeap.poll(); 
        int secondMin = minHeap.poll();
        minHeap.add(firstMin > (Integer.MAX_VALUE - secondMin)/2 ? k : ((firstMin *2) + secondMin));
      count++;
     } 
    return count; 
    }
}