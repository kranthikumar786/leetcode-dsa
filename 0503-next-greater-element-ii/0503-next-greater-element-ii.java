class Solution {
    public int[] nextGreaterElements(int[] nums) {
       int n = nums.length;
       int ans[] = new int[n];
       Stack<Integer>st = new Stack<>();
       for(int i = 2*n-1; i >= 0 ; i--) {
           int idx = i%n;
           while(!st.isEmpty() && nums[st.peek()] <= nums[idx]){
                 st.pop();
           }
           if(idx < n){
              ans[idx] = st.isEmpty() ? -1: nums[st.peek()];
           }
         st.push(idx);   
       }
      return ans; 
    }
}

/**
class Solution {
    public int[] nextGreaterElements(int[] nums) {
      int n = nums.length;
      int ans[] = new int[n];
      Stack<Integer>st = new Stack<>();
      for(int i = 0 ; i < n ; i++) {
            while(!st.isEmpty() && nums[st.peek()] < nums[i]){
                  st.pop();
            }   
          st.push(i);  
      }
      for(int  i = n-1; i >= 0 ;i--) {
           while(!st.isEmpty() && nums[st.peek()] > nums[i]){
                st.pop();
           }
         ans[i] = st.isEmpty() ? -1 ; nums[st.peek()];
         st.push(i);  
         }     
      }
     return ans; 
    }
}


/**

class Solution {
    public int[] nextGreaterElements(int[] nums) {
      int n = nums.length;
      int ans[] = new int[n];
      Stack<Integer>st = new Stack<>();
      for(int i = 0 ; i < n ; i++) {
            while(!st.isEmpty() && nums[st.peek()] < nums[i]){
                  st.pop();
            }   
          st.push(i);  
      }
      for(int  i = n-1; i >= 0 ;i--) {
           while(!st.isEmpty() && nums[st.peek()] > nums[i]){
                st.pop();
           }
         ans[i] = st.isEmpty() ? -1 ; nums[st.peek()];
         st.push(i);  
         }     
      }
     return ans; 
    }
}

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

INput: 
[1,8,-1,-100,-1,222,1111111,-111111]

output : 
[8,222,222,222,222,1111111,-1,1]

Expected  :
[8,222,222,-1,222,1111111,-1,1]
 */