class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int n = asteroids.length;
        Stack<Integer>st = new Stack<>(); 
        for(int a : asteroids) {
              boolean Destoryed = false;
              while(!st.isEmpty() && st.peek() > 0 && a < 0) {
                   if(Math.abs(st.peek()) > Math.abs(a)){
                       Destoryed = true;
                       break;  
                   } else if(Math.abs(st.peek()) < Math.abs(a)){
                        st.pop();
                   } else{
                    st.pop();
                    Destoryed = true;
                    break;
                   }
              }
             if(!Destoryed){
                st.push(a);
             } 
        }
      int ans[] = new int[st.size()];
      for(int i = st.size()-1; i >= 0 ;i--){
           ans[i] = st.pop();
      }
  return ans;
    }
}

// class Solution {
//     public boolean isSameSign(int p , int n){
//          return((p > 0 && n > 0) || 
//                    (p < 0 && n < 0));
//     }
//     public int[] asteroidCollision(int[] asteroids) {
//         int  n = asteroids.length;
//         int ans[] = new int[n];
//          Stack<Integer> st = new Stack<>();
//          for(int i = 0 ; i < n ;i++) {
//                while(!st.isEmpty() && !isSameSign(asteroids[st.peek()], asteroids[i])){
//                      if(abs(asteroids[st.peek()) >  abs(asteroids[i]))){
//                         st.pop();
//                      }
//                }
//              st.push(i);   // 5: 
//          }
//         int i = 0 ;
//         while(!st.isEmpty()){
//               ans[i] = asteroids[st.pop()];
//               i++;
//         }

//    Arrays.reverse(ans);
//    return
//         /**
//          + right
//          - left :
//          5 , 10 : -5: 
//              5, 10 : 

// --------------------
//    5 -5 10 : 
//    5 -5: 10 :  

 
//  ====================
//  [10,2,-5] : 
//   10 , 2 , -5: 
//        2 < 5: 
//    10, -5: 

//    10  left :


//    ================
//    [3,5,-6,2,-1,4] : 
//     3 5 -6
//      3 -6: 
//        -6 : 2
//        6 reches out of it : in ans : -6: 

//         2 -1:
//         2 4 :

//    if size == 1:



//          */
 
 
 
//     }
// }