class Solution {
    public int[] topKFrequent(int[] nums, int k) {
    HashMap<Integer,Integer>hm = new HashMap<>();
    for(int val : nums){
        hm.put(val,hm.getOrDefault(val,0)+1);
    }
   PriorityQueue<Map.Entry<Integer,Integer>>pq = new PriorityQueue<>((a,b)->b.getValue()-a.getValue());
    pq.addAll(hm.entrySet());
    int ans[] = new int[k];
     while(k-- > 0) {
        Map.Entry<Integer,Integer>cur = pq.poll();
        ans[k] = cur.getKey();
     }   
       return ans;
    }
}