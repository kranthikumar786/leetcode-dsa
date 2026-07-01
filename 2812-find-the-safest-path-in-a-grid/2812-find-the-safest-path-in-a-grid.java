class Solution {
    int[][]dirs = new int[][]{{-1,0},{1,0},{0,-1},{0,1}};
    public int maximumSafenessFactor(List<List<Integer>> grid){
        int[][]mat = new int[grid.size()][ grid.get(0).size()];
        int ans = 0;
        int l = 0,h = grid.size() + grid.get(0).size();
        populateMatrix(mat,grid);
        while(l <= h){
            int mid = (h - l) / 2 + l;
            if(check(mat,mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
    private boolean check(int[][]mat,int k){
        if(mat[0][0] < k) return false;
        int m = mat.length,n = mat[0].length; 
        Queue<int[]> q = new LinkedList<>();
        boolean[][]visited = new boolean[m][n];
        q.offer(new int[]{0,0});
        visited[0][0] = true;
        while(!q.isEmpty()){
            int size = q.size();
            while(size-- != 0){
                int[] node = q.poll();
                if(node[0] == m - 1 && node[1] == n - 1) return true;
                for(int[] move : dirs){
                    int r = node[0] + move[0],c = node[1] + move[1];
                    if(r >= m || c >= n || r < 0 || c < 0 || visited[r][c]){
                        continue;
                    }
                    if( mat[r][c] >= k){
                        visited[r][c] = true;
                        q.offer(new int[]{r,c});
                    }
                }
            }
        }
        return false;
    }
    private void populateMatrix(int[][]mat,List<List<Integer>> grid){
        int m = mat.length,n = mat[0].length; 
        boolean[][]visited = new boolean[m][n];
        Queue<int[]> q = new LinkedList<>();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid.get(i).get(j) == 1){
                    q.offer(new int[]{i,j,0});
                    visited[i][j] = true;
                }
            }
        }
        while(!q.isEmpty()){
            int size = q.size();
            while(size-- != 0){
                int[] node = q.poll();
                mat[node[0]][node[1]] = node[2];
                for(int[] move : dirs){
                    int r = node[0] + move[0],c = node[1] + move[1];
                    if(r >= m || c >= n || r < 0 || c < 0 || visited[r][c]){
                        continue;
                    }
                    visited[r][c] = true;
                    q.offer(new int[]{r,c,node[2] + 1});
                }
            }
        }
    }
}