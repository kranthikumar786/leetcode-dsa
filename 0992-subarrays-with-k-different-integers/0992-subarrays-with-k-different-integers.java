class Solution {
    private int atMost(int[] nums, int k) {
    HashMap<Integer, Integer> hm = new HashMap<>();
    int l = 0, r = 0, ans = 0;
    int n = nums.length;
    while (r < n) {
        int v = nums[r];
        hm.put(v, hm.getOrDefault(v, 0) + 1);
        while (hm.size() > k) {
            int lV = nums[l];
            hm.put(lV, hm.get(lV) - 1);
            if (hm.get(lV) == 0) {
                hm.remove(lV);
            }
            l++;
        }
        ans += (r - l + 1);
        r++;
    }
    return ans;
}
    public int subarraysWithKDistinct(int[] nums, int k) {
       return atMost(nums, k) - atMost(nums, k - 1);
    }
}
/**

 int ans = 0 ; 
    int n = nums.length;
    for(int i = 0 ; i < n ;i++) {
        HashMap<Integer,Integer>hm = new HashMap<>();
        for(int j = i ; j < n ;j++) {
            int cnt = hm.getOrDefault(nums[j],0);
            hm.put(nums[j], cnt+1);  
             if(hm.size() == k){
                  ans++;
             }
             if(hm.size() > k ){
                  break;
             }
        }
    }
    return ans;
 */