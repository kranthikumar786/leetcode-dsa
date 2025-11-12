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
    public void flatten(TreeNode root) {
       if(root == null) return;
       Stack<TreeNode>st = new Stack<>();
       TreeNode cur = root;
       st.push(cur);
       while(!st.isEmpty()) {
           cur = st.pop();
           if(cur.right != null) st.push(cur.right);
           if(cur.left != null) st.push(cur.left);
           if(!st.isEmpty()){
               cur.right = st.peek();
               cur.left = null;
               }

         cur = cur.right;
       }    
    }
}
/**

TreeNode cur = root;
       Stack<TreeNode>st = new Stack<>();
         while(cur != null || !st.isEmpty()) {
                 if(cur != null && cur.right != null){
                    st.push(cur.right);
                    cur.right = cur.left;
                    cur.left = null;
                 } else{
                   cur.right = st.isEmpty() ? null :st.pop();
                   cur.left = null; 
                 }
               cur = cur.right;  
         }
 */