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

    public void level(TreeNode root , List<List<Integer>>ans){
      Queue<TreeNode> Q = new LinkedList<>();
      Q.add(root);
      while( Q.size() > 0 ) {
        int levelSize = Q.size();
       List<Integer>a = new ArrayList<>();
        while( levelSize > 0){
            TreeNode node = Q.poll();
           // Q.pop();
             if(node == null) 
                 continue;
             a.add(node.val);
           if(node.left != null){
            Q.add(node.left);
           }
           if(node.right != null){
            Q.add(node.right);
           }
           levelSize--;
        } 
          ans.add(a); 
      }
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> ans = new ArrayList<>();
    if(root == null)
        return ans;
    level(root,ans);
     return ans;   
    }
}