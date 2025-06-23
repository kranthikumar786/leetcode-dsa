class Solution {
    public int[][] kClosest(int[][] points, int k) {
       PriorityQueue<int[]>pq = new PriorityQueue<>((a,b) -> (
        (a[0]*a[0] + a[1]*a[1]) - (b[1]*b[1] + b[0]*b[0])  
       )); 
      for(int[] point : points){
        pq.add(point);
      }
     int[][] ans = new int[k][2];
     int i  = 0 ;
     while(i < k){
        ans[i++] = pq.poll();
     }
    return ans; 
    }
}

/**

class Solution {
    public int[][] kClosest(int[][] points, int k) {
      
     PriorityQueue<int[]>pq = new PriorityQueue<>((a,b)->(a-b));   
      int n = points.size();
     for(int i = 0 ; i < n ;i++) {
        int x = points[i][0];
        int y = points[i][1];
        int val = (x * x) + (y*y);
        int s = Math.sqrt(val);
        pq.add(new int[]{s,i});
     }

    int ans[][] = new int[k][2];
    int i = 0 ;
      while(i < k){
        ans[i][0] = pq.pop();
        i++;
      } 
  return ans;
    }
}


 */