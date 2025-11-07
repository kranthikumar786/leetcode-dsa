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
    public List<Integer> preorderTraversal(TreeNode root) {
     List<Integer>ans = new ArrayList<>();
       Stack<TreeNode>st = new Stack<>(); 
        TreeNode cur = root;
         while(cur != null || !st.isEmpty()) {
                while(cur != null) {
                    ans.add(cur.val);
                    if(cur.right != null)
                      st.push(cur.right);
                    cur = cur.left;  
                }
                 if(!st.isEmpty())
                  cur = st.pop();
         }
      return ans;
    }
}