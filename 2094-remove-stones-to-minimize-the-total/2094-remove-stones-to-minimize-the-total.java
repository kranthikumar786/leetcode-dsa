class Solution {
    public int minStoneSum(int[] piles, int k) {
     int minimizedTotal = 0;
     PriorityQueue<Integer>maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
     int totalSum = 0;
      for(int pile : piles){
          totalSum += pile;
          maxHeap.add(pile); 
     }
      minimizedTotal = totalSum;
       while (k > 0) {
            k--;
            int maxElement = maxHeap.poll();
            minimizedTotal -= maxElement;
            int rem = (maxElement%2 == 0 ? 0 : 1);
            maxElement = (maxElement/2) ;
            maxElement += rem;
            minimizedTotal += maxElement;
            maxHeap.add(maxElement);
      }
   return minimizedTotal;
    }
}