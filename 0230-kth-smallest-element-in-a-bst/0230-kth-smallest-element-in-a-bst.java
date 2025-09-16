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
   ArrayList<Integer> sorted = new ArrayList<>();
   void inorderTravesal(TreeNode root) {
       if(root != null) {
         inorderTravesal(root.left);
         sorted.add(root.val);
         inorderTravesal(root.right);
       }
   }
    public int kthSmallest(TreeNode root, int k) {
          inorderTravesal(root);
          return sorted.get(k-1);
        /**
        BST inorder travesal gives the sorted order elements :
         so stor ein in array , then find the K-1 elemnte return it :
       TC: O(n)
       SC: O(n)
         **/
    }
}