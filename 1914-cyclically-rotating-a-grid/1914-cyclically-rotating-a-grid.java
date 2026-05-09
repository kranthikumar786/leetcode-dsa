class Solution {
    public int[][] rotateGrid(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;

        int layers = Math.min(n, m)/2;

        for(int layer=0; layer<layers; layer++){
            int top = layer;
            int left = layer;
            int bottom = n - layer - 1;
            int right = m - layer - 1;

            ArrayList<Integer> list = new ArrayList<>();

            for(int i=left; i<=right; i++){
                list.add(grid[top][i]);
            }

            for(int i=top+1; i<=bottom-1; i++){
                list.add(grid[i][right]);
            }

            for(int i=right; i>=left; i--){
                list.add(grid[bottom][i]);
            }

            for(int i=bottom-1; i>=top+1; i--){
                list.add(grid[i][left]);
            }

            int size = list.size();
            int rotate = k % size;

            ArrayList<Integer> rotated = new ArrayList<>();

            for(int i=0; i<size; i++){
                rotated.add(list.get((i+rotate) % size));
            }

            int idx = 0;

            for(int i=left; i<=right; i++){
                grid[top][i] = rotated.get(idx++);
            }

            for(int i=top+1; i<=bottom-1; i++){
                grid[i][right] = rotated.get(idx++);
            }

            for(int i=right; i>=left; i--){
                grid[bottom][i] = rotated.get(idx++);
            }

            for(int i=bottom-1; i>=top+1; i--){
                grid[i][left] = rotated.get(idx++);
            }
        }
        return grid;
    }
}