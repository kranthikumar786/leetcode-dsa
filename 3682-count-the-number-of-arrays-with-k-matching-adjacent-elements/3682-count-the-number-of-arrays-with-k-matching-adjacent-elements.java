class Solution {
    private static final int MOD = 1_000_000_007;

    private long modInverse(long a, long mod) {
        long result = 1;
        long power = mod - 2;

        while (power > 0) {
            if ((power & 1) == 1) {
                result = result * a % mod;
            }
            a = a * a % mod;
            power >>= 1;
        }

        return result;
    }

    private int nCr(int n, int r) {
        if (r > n) {
            return 0;
        }
        if (r == 0 || r == n) {
            return 1;
        }

        long result = 1;
        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) % MOD;
            result = result * modInverse(i, MOD) % MOD;
        }

        return (int) result;
    }

    private long binExpo(long a, long b) {
        long result = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                result = result * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return result;
    }

    public int countGoodArrays(int n, int m, int k) {
        long base = m * binExpo(m - 1, n - k - 1) % MOD;
        long result = base * nCr(n - 1, k) % MOD;
        return (int) result;
    }
}
