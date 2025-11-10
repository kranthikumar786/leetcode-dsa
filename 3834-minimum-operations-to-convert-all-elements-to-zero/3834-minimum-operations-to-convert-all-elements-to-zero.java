class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        Stack<Integer> st = new Stack<>();
        st.push(0);
        for (int num : nums) {
            while (!st.isEmpty() && st.peek() > num) {
                st.pop();
            }
            if (st.isEmpty() || st.peek() < num) {
                if (num > 0) {
                    ans++;
                    st.push(num);
                }
            }
        }
        return ans;
    }
}

/**
class Solution {
    public int minOperations(int[] nums) {
       int n = nums.length;
       if(n == 0) return 0;
       Stack<Integer>st = new Stack<>();
       int index =  0; 
       int cnt = 0;
       while(index < n ) {
            while(!st.isEmpty() &&  st.peek() >= nums[index]) {
                   cnt++;
                   st.pop();
            }
          st.push(nums[index++]);  
       }
      return cnt; 
         first funny idea : 
           simply get hashMap then return hashMap size : boom : 
           ex 3 : boommm
              
            find minValue : find range of min values: 
            ex 2:  [3,1,2,1]
                   first minValue = 1: 
                     so find that ragne :
                       [1,2,1] : 
                       [3,0,2,0]  : 
                         next  minValllue   : [3,0,0,0] : 2:
                        3

 ----------------------
    [1,2,1,2,1,2]
     
     0 2 0 2 0 2 : 

  next min : 2 
       0  0 0 0 0 : 

      0 0 0 0 0 0 
    }
}
*/