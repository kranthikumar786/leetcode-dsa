class Solution {
    public int[] nextGreaterElements(int[] nums) {
      int n = nums.length;
      int ans[] = new int[n];
      for(int i = 0 ; i < n ;i++) {
           int nextMax = -1;
           for(int j = i+1; j < n*2; j++) {
                int idx = j%n;
                if(idx == i)
                     break;
                     if(nums[idx] > nums[i]){
                          nextMax = nums[idx];
                          break;
                     }  
                }
        ans[i] = nextMax;    
      }
     return ans; 
    }
}


/**
INput: 
[1,8,-1,-100,-1,222,1111111,-111111]

output : 
[8,222,222,222,222,1111111,-1,1]

Expected  :
[8,222,222,-1,222,1111111,-1,1]
 */