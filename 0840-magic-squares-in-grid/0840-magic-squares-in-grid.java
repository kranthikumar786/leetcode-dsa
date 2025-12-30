class Solution {
    public int numMagicSquaresInside(int[][] g) {
        int n = g.length, m = g[0].length, ans = 0;
        for (int i = 0; i <= n - 3; i++)
            for (int j = 0; j <= m - 3; j++)
                if (isMagic(g, i, j)) ans++;
        return ans;
    }

    boolean isMagic(int[][] g, int r, int c) {
        if (g[r+1][c+1] != 5) return false;

        int mask = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                int v = g[r+i][c+j];
                if (v < 1 || v > 9 || (mask & (1 << v)) != 0) return false;
                mask |= 1 << v;
            }

        return g[r][c]+g[r][c+1]+g[r][c+2] == 15 &&
               g[r+1][c]+g[r+1][c+1]+g[r+1][c+2] == 15 &&
               g[r+2][c]+g[r+2][c+1]+g[r+2][c+2] == 15 &&
               g[r][c]+g[r+1][c]+g[r+2][c] == 15 &&
               g[r][c+1]+g[r+1][c+1]+g[r+2][c+1] == 15 &&
               g[r][c+2]+g[r+1][c+2]+g[r+2][c+2] == 15 &&
               g[r][c]+g[r+1][c+1]+g[r+2][c+2] == 15 &&
               g[r][c+2]+g[r+1][c+1]+g[r+2][c] == 15;
    }
}
