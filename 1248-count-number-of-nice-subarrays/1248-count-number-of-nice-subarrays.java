class Solution {
    public int Counting(int nums[],int g){
        int l = 0 , r = 0 , sum = 0, cnt = 0, n = nums.length;
        while(r < n) {
            sum += (nums[r]%2);
            while(sum > g){
                sum -= (nums[l]%2); 
               l++;
            }
           cnt += (r-l+1);  
           r++;
        }
        return cnt; 
    }
    public int numberOfSubarrays(int[] nums, int k) {
       return Counting(nums,k) - Counting(nums,k-1);
    }
}
/**

int ans = 0 ;
     int n = nums.length;
     int l = 0 , r = 0 ;
      int cnt = 0;
      while(r < n) {
         if(nums[r]%2 != 0){
            cnt++;
         }
          if(cnt == k){
            ans++;
          }
          while(l < r && cnt > k){
             if(nums[l]%2 != 0){
                cnt--;
             }
             if(cnt == k){
                ans++;
             }
            l++; 
          }
         r++;  
      }
     return ans; 



for(int i = 0 ; i < n ; i++) {
           int cnt = 0 ;
           for(int j = i ; j < n ;j++) {
                 if(nums[j]%2 != 0){
                    cnt++;
                 }
                 if(cnt == k){
                        ans++;
                      }
                 if(cnt > k){break;} 
           }
     }
 */