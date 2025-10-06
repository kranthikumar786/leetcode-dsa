class Solution {
    public int swimInWater(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        PriorityQueue<int[]>pq = new PriorityQueue<>((a,b)->a[0]-b[0]);
        int[][] directions = {{0,1},{1,0},{0,-1},{-1,0}};
        Set<String> seen = new HashSet<>();
        pq.offer(new int[]{grid[0][0],0,0});
         while(!pq.isEmpty()) {
             int[] cur = pq.poll();
             int max_D = cur[0], r = cur[1], c = cur[2];
             String key = r +","+c;
             if(seen.contains(key)) continue;
             seen.add(key);
             if(r == m-1 && c == n-1) return max_D;
             for(int[] dir : directions) {
                  int nr = r + dir[0] , nc = c + dir[1];
                 if(nr >=0 && nr < m && nc >=0 && nc < n && !seen.contains(nr +","+nc) ) {
                       int new_d = Math.max(max_D,grid[nr][nc]);
                       pq.offer(new int[]{new_d,nr,nc});
                 } 
             }
         }
    return -1;
    }
    
}