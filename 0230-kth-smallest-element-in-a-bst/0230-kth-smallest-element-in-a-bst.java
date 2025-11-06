/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = -1;
    int cnt = 0;
      void preOrder(TreeNode root, int k){
          if(root == null) return ;
          preOrder(root.left,k);
          cnt++;
          if(cnt == k && ans == -1){
               ans = root.val;
              System.out.println(ans); 
          }
          preOrder(root.right,k);
      }
    public int kthSmallest(TreeNode root, int k) {
     preOrder(root,k);
     return ans;
    }
}