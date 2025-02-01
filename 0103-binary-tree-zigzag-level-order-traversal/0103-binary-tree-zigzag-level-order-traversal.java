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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
   List<List<Integer>>ans = new ArrayList<>();
    if(root == null)
     return ans;
   Queue<TreeNode> Q = new LinkedList<>();
   Q.add(root);
    int levelQ = -1;
   while(Q.size() > 0) {
    int level = Q.size();
   levelQ++;
    List<Integer>levelE = new ArrayList<>();
       while(level-- > 0){
         TreeNode currentRoot = Q.poll();
          if(currentRoot == null)
               continue;
         levelE.add(currentRoot.val);
         if(currentRoot.left != null)
         Q.add(currentRoot.left);
         if(currentRoot.right != null)
         Q.add(currentRoot.right); 
       }
       if(levelQ%2 ==1)
        Collections.reverse(levelE);
       ans.add(levelE); 
   }
    return ans;    
    }
}