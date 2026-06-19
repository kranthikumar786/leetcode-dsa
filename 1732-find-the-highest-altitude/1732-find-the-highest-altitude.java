class Solution {
    public int largestAltitude(int[] gain) {
        int len = gain.length;
        int max = gain[0];

        for(int i = 1; i < len; i++){
            gain[i] = gain[i] + gain[i-1];
            max = Math.max(max, gain[i]);
        }

        return max < 0 ? 0 : max;
    }
}