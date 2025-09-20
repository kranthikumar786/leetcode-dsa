class Solution {
    public int kthSmallest(int[][] matrix, int k) {
     PriorityQueue<Integer>pq = new PriorityQueue<>((a,b) -> b-a); 
     int totalRows = matrix.length;
     for(int row = 0 ; row < totalRows ; row++ ){
           for(int col = 0 ;col < totalRows; col++) {
             pq.add(matrix[row][col]);
             if(pq.size() > k){ // for kth value , not for kth distinct value
                  pq.poll();
             }
           }
     }
     return pq.peek();
      /**
       1 5 9 10 11 12 13 13 15
     
minHeap :     1 5 9 10 11 12 13 13 : 
maxHeap : 13 13 12 11 10 9 5 1 : 

      if(pq.size() == k) {
           return pr.peek();
      }
       */  
    }
}
