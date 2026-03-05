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
    public List<Integer> rightSideView(TreeNode root) {
       List<Integer> ans = new ArrayList<>();
         if(root == null) return ans;
       Queue<TreeNode>Q = new LinkedList<>();
       Q.add(root);
       while(!Q.isEmpty()){
            int eleSize = Q.size();
         for(int i  = 0 ; i < eleSize ; i++) {
             TreeNode ele = Q.poll();
             if(i == eleSize-1){
                ans.add(ele.val);
             }
            if(ele.left != null){
                Q.add(ele.left);
            } 
            if(ele.right != null){
                Q.add(ele.right);
            } 
         }
       }
     return ans;
    }
}