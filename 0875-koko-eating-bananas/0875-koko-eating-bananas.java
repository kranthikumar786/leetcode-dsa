class Solution {

    public boolean canEat(int[] piles, int h, int k) {
        long hours = 0;  
        for (long p : piles) {
            hours += (p + k - 1) / k; 
            if (hours > h) return false; 
        }
        return hours <= h;
    }

    public int minEatingSpeed(int[] piles, int h) {

        int l = 1;
        int r = Arrays.stream(piles).max().getAsInt();
        int ans = r;

        while (l <= r) {
            int k = l + ((r - l) >> 1);

            if (canEat(piles, h, k)) {
                ans = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return ans;



     /***
     Input: piles = [3,6,7,11], h = 8
                     
                      3 + 6 + 7 + 11 =
                      27 : total banannna : 
                      4 * 8 = 32 : 
                      16
                       8
                      --
                       24

                      8 hour : 

     Output: 4



piles = [30,11,23,4,20], h = 5
 
       30
       11
       41
       23 
       64
        4
       68
       20 
       88

       88/5 : 

       30 * 5 = 150 : 
         
    
    Output: 30

      */   
    }
}