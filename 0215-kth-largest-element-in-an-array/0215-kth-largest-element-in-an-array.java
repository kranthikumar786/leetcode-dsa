class Solution {
    public int findKthLargest(int[] nums, int k) {
    Queue<Integer>pq = new PriorityQueue<>((a,b)->(b-a));
      for(int num : nums){
        pq.add(-num);
        if(pq.size() > k) {
            pq.poll();
        }
      }
      return -(pq.peek());
    }
}