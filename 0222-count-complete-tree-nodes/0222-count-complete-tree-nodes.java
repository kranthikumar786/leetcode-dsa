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
    public int countNodes(TreeNode root) {
     int ans = 0;
     if(root == null) return 0;
      Queue<TreeNode>q = new LinkedList<>();
       q.add(root); 
        while(!q.isEmpty()) {
            int s = q.size();
            ans += s;
            for(int i = 0 ;i < s ;i++){
                  TreeNode cur = q.poll();
                   if(cur.left != null){
                      q.add(cur.left);
                   }
                    if(cur.right != null) {
                        q.add(cur.right);
                    }
            }
        }
        return ans;
    }
}