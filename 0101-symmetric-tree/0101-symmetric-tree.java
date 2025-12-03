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
    public boolean isSymmetric(TreeNode root) {
       if(root == null) return true;
       Queue<TreeNode>q = new LinkedList<>();
       q.add(root.left);
       q.add(root.right);
        while(!q.isEmpty()){
         TreeNode leftRoot = q.poll();
         TreeNode rightRoot = q.poll();
         if(leftRoot == null && rightRoot == null) continue;
         if(leftRoot == null || rightRoot == null) return false;
         if(leftRoot.val != rightRoot.val) return false;
         q.add(leftRoot.left);
         q.add(rightRoot.right);
         q.add(leftRoot.right);
         q.add(rightRoot.left);
        }
       return true; 
    }
}
/**
ArrayDeque<TreeNode>leftst =  new  ArrayDeque<>();
       ArrayDeque<TreeNode>rightst = new  ArrayDeque<>();
        TreeNode leftRoot  = root.left ;
        TreeNode rightRoot = root.right;
         while((leftRoot != null && rightRoot != null) || !leftst.isEmpty() && !rightst.isEmpty()) {
                while(leftRoot != null && rightRoot != null) {
                        if(leftRoot.val != rightRoot.val){return false;}
                        leftst.add(leftRoot);
                        rightst.add(rightRoot);
                         leftRoot = leftRoot.left;
                         rightRoot = rightRoot.right;
                }
               rightRoot = rightst.pop();
               leftRoot = leftst.pop();
               if(leftRoot.val != rightRoot.val)return false;
               rightRoot  =rightRoot.left;
               leftRoot = leftRoot.right;
         }
 */