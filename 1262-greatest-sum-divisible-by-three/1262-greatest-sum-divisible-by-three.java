class Solution {
    public int maxSumDivThree(int[] nums) {

        int[] dp = new int[]{0, Integer.MIN_VALUE, Integer.MIN_VALUE};

        for (int x : nums) {
            int[] next = dp.clone();
            int mod = x % 3;

            for (int oldMod = 0; oldMod < 3; oldMod++) {
                if (dp[oldMod] == Integer.MIN_VALUE) continue;
                int newMod = (oldMod + mod) % 3;
                next[newMod] = Math.max(next[newMod], dp[oldMod] + x);
            }

            dp = next;
        }

        return dp[0];
    }
}



// class Solution {
//     public int maxSumDivThree(int[] nums) {
//         /**
//           3 6 1 8 = > 18%3 == 0 : 
//          i > n : 
//           return :
//          if(sum %3 == 0) {
//             bigSum = Math.max(bigSum,sum);
//          }  
//           rec(i+1, sum+arr[i]);
//           rec(i,sum) :     
//          */
//     }
// }