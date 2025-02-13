class Solution {
    public int minOperations(int[] nums, int k) {
     PriorityQueue<Integer> minHeap = new PriorityQueue<>();   
     for(int num : nums){
        if(num < k)
        minHeap.add(num);
     }
     int count = 0 ;
     while (minHeap.size() > 0 && minHeap.peek() < k) {
           count++;
        int firstMin = minHeap.poll(); 
        if(minHeap.size() == 0){
            break;
        }
        int secondMin = minHeap.poll();
        int res = firstMin > (Integer.MAX_VALUE - secondMin)/2 ? k : ((firstMin *2) + secondMin);
       if(res < k)
        minHeap.add(res);
     } 
    return count; 
    }
}
/**
tc : O(NlogN)
sc : O(N)
 */