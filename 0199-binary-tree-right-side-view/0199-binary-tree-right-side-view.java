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
    List<Integer>ans = new ArrayList<>();
    if(root == null){
        return ans;
    }
    Queue<TreeNode> Q = new LinkedList<>();
    Q.add(root);
 while(Q.size() > 0) {
    int levelSize = Q.size();
     for(int i = 0 ; i < levelSize; i++) {
         TreeNode currentNode = Q.poll();
          if(currentNode == null)
              continue;
          if(i == levelSize-1){
            ans.add(currentNode.val);
          }
          if(currentNode.left != null){
            Q.add(currentNode.left);
          }
          if(currentNode.right != null){
            Q.add(currentNode.right);
          }
     }
     }
    return ans;   
 
 }
}