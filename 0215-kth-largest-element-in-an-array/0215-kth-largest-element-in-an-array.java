class Solution {
    public int findKthLargest(int[] nums, int k) {

       Queue<Integer>Q = new PriorityQueue<>();
            int n  = nums.length;
        for(int i = 0 ; i < n ;i++) {
            Q.add(nums[i]);
            if(Q.size() > k) {
                Q.poll();
            }    
        } 
return Q.peek();
       /**
        [3,2,1,5,6,4], k = 2
             5 6 : 

        */
    }
}