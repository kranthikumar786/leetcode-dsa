class Solution {
    public int pivotIndex(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            long sumL = 0, sumR = 0;

            for (int l = 0; l < i; l++) {
                sumL += arr[l];
            }

            for (int r = i + 1; r < n; r++) {
                sumR += arr[r];
            }

            if (sumL == sumR) {
                return i;
            }
        }

        return -1; 
    }
}
