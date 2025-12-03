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
    public List<Integer> inorderTraversal(TreeNode root) {
       List<Integer>ans = new ArrayList<>();
         TreeNode cur = root;
           while(cur != null) {
               if(cur.left == null){
                  ans.add(cur.val);
                  cur = cur.right;
               } else{
                      TreeNode pre = cur.left;
                      while(pre.right != null && pre.right != cur){
                          pre = pre.right;
                      }
                       if(pre.right == null){
                          pre.right = cur;
                          cur = cur.left;
                       } else{
                           pre.right = null;
                           ans.add(cur.val);
                           cur = cur.right;
                       } 
               }
           }  
        return ans; 
    }
}
/**

TreeNode cur = root;
       Stack<TreeNode>st = new Stack<>();
        while(cur != null || !st.isEmpty()) {
              while(cur != null){
                st.push(cur);
                 cur = cur.left;
              }
              cur = st.pop();
              ans.add(cur.val);
              cur = cur.right;
        }
while(cur != null) {
             if(cur.left == null){
                 ans.add(cur.val);
                 cur = cur.right;
             } else{
                 TreeNode prev = cur.left;
                  while(prev.right != null &&  prev.right != cur){
                        prev = prev.right;
                  }
                   if(prev.right == null){
                       prev.right = cur;
                        cur= cur.left;
                   } else{
                       prev.right = null;
                       ans.add(cur.val);
                       cur = cur.right;
                   }
             }
        }

 */