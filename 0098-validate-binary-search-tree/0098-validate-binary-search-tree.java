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
    TreeNode prev = null;
    public boolean isValidBST(TreeNode root) {
      Stack<TreeNode>st = new Stack<>();
     TreeNode cur = root, prev = null;
     while(cur != null || !st.isEmpty()){
             while(cur != null) {
                st.push(cur);
                cur = cur.left;
             }
            cur = st.pop();
             if(prev != null && prev.val >= cur.val) return false;
            prev = cur;
            cur = cur.right;    
     }
     return true; 
    }
}
/**
   if(root == null) return true;
       if(!isValidBST(root.left)) return false;
       if(prev != null && prev.val >= root.val) return false;
        prev = root;
        return isValidBST(root.right);
 */