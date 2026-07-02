class Solution {
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int n = grid.size();
        int m = grid.get(0).size();

        int[] dr = new int[] {0, 0, 1, -1};
        int[] dc = new int[] {1, -1, 0, 0};

        boolean[][][] visited = new boolean[n][m][health + 1];
        Queue<int[]> bfs = new LinkedList<>();

        bfs.add(new int[] {0, 0, health - grid.get(0).get(0)});
        visited[0][0][health - grid.get(0).get(0)] = true;

        while (!bfs.isEmpty()) {
            int[] curr = bfs.poll();
            int r = curr[0];
            int c = curr[1];
            int h = curr[2];

            if (r == n - 1 && c == m - 1 && h > 0) {
                return true;
            }

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (isvalid(nr, nc, n, m)) {
                    int nh = h - grid.get(nr).get(nc);

                    if (nh >= 0 && !visited[nr][nc][nh]) {
                        visited[nr][nc][nh] = true;
                        bfs.add(new int[] {nr, nc, nh});
                    }
                }
            }
        }

        return false;
    }

    private boolean isvalid(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }
}