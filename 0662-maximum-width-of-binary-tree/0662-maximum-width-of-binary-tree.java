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
     class Q{
        TreeNode node;
        int index;
        Q(TreeNode node, int index){
            this.node = node;
            this.index = index;
        }
        public int getIndex(){
            return this.index;
        }
        public TreeNode getTreeNode(){
            return this.node;
        }
     }
    public int widthOfBinaryTree(TreeNode root) {
       if(root == null) return 0;
       int ans = 0;
      Queue<Q>q = new LinkedList<>();
      q.add(new Q(root,0));
        while(!q.isEmpty()) {
            int s = q.size();
            int first = 0, last = 0;
            for(int i = 0 ; i < s; i++) {
                Q cur = q.poll();
                int index = cur.getIndex();
                TreeNode curN = cur.getTreeNode();
                if(i == 0){ 
                   first = index;
                }
                 if(i == s-1){
                    last = index;
                 }
                 int v = 2*index;

                 if(curN.left != null)
                    q.add(new Q(curN.left,v+1));
                 if(curN.right != null)
                   q.add(new Q(curN.right,v+2));
            }
            ans = Math.max(ans,last-first+1);
        }
       return ans; 
    }
}