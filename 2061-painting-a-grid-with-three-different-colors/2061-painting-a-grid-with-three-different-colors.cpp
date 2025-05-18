class Solution {
    const int MOD = 1e9 + 7;
    int n, m;
    int memo[1001][6][4][4][4][4][4][4];
    long long solveRecursively(int i, int j, int left, int first, int second, int third, int fourth, int fifth) {
        if(i == n) return 1;
        if(memo[i][j][left + 1][first + 1][second + 1][third + 1][fourth + 1][fifth + 1] != -1) 
            return memo[i][j][left + 1][first + 1][second + 1][third + 1][fourth + 1][fifth + 1];

        long long ans = 0;
        bool nextLine = (j + 1 == m);
        for(int k = 0; k < 3; k++) {
            if(left == k) continue;

            if(j == 0 && first != k) {
                if(nextLine) ans += solveRecursively(i + 1, 0, -1, k, second, third, fourth, fifth);
                else ans += solveRecursively(i, j + 1, k, k, second, third, fourth, fifth);
            } else if(j == 1 && second != k) {
                if(nextLine) ans += solveRecursively(i + 1, 0, -1, first, k, third, fourth, fifth);
                else ans += solveRecursively(i, j + 1, k, first, k, third, fourth, fifth);
            } else if(j == 2 && third != k) {
                if(nextLine) ans += solveRecursively(i + 1, 0, -1, first, second, k, fourth, fifth);
                else ans += solveRecursively(i, j + 1, k, first, second, k, fourth, fifth);
            } else if(j == 3 && fourth != k) {
                if(nextLine) ans += solveRecursively(i + 1, 0, -1, first, second, third, k, fifth);
                else ans += solveRecursively(i, j + 1, k, first, second, third, k, fifth);
            } else if(j == 4 && fifth != k) {
                ans += solveRecursively(i + 1, 0, -1, first, second, third, fourth, k);
            }
        }
        return memo[i][j][left + 1][first + 1][second + 1][third + 1][fourth + 1][fifth + 1] = ans % MOD;
    }
public:
    int colorTheGrid(int m, int n) {
        this->n = n;
        this->m = m;
        memset(memo, -1, sizeof(memo));
        return solveRecursively(0, 0, -1, -1, -1, -1, -1, -1) % MOD;
    }
};
