/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
       if(root == null || root.val == p.val || root.val == q.val){return root;}
        TreeNode leftN = lowestCommonAncestor(root.left,p,q);
        TreeNode rightN = lowestCommonAncestor(root.right,p,q);
         if(leftN != null && rightN != null ){return root;}
        return leftN == null ? rightN : leftN;   
    }
}
/**
 if(root == null){return null;}
        if(leftN != null &&  rightN != null) {return root;}
        if(root.val == p.val || root.val == q.val){return root;}
        leftN = lowestCommonAncestor(root.left,p,q);
        rightN = lowestCommonAncestor(root.right,p,q);
        return leftN == null ? rightN : leftN;
 */