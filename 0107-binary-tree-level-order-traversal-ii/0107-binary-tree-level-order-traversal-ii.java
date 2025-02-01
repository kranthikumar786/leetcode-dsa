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
   public int maxDepth(TreeNode root){
      if(root == null){
         return 0;
      }
    int leftDepth =  maxDepth(root.left);
    int rightDepth =  maxDepth(root.right);
   return Math.max(leftDepth , rightDepth) +1;  
   }
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
       List<List<Integer>> ans = new ArrayList<>(); 
        if( root == null){
            return ans;
        }
      int depthOfTree = maxDepth(root);
    //  depthOfTree--;
    //    for(int i = 0 ; i <= depthOfTree; i++){
    //      ans.add(new ArrayList<>());
    //    }
    Queue<TreeNode> Q = new LinkedList<>();
    Q.add(root);
    while (Q.size() > 0){
      int levelSize = Q.size();
         List<Integer> ele = new ArrayList<>();
    for(int i = 0 ; i < levelSize ; i++) {
          TreeNode currentNode = Q.poll();
            if(currentNode == null)
                continue;
            ele.add(currentNode.val);
           if(currentNode.left != null)
           Q.add(currentNode.left);
          if(currentNode.right != null)
          Q.add(currentNode.right);   
    }
  //  ans.add(0, ele);
//  ans.set(depthOfTree,ele);
//    depthOfTree--;
ans.add(ele);
    }
   Collections.reverse(ans);
   // Collections.reverse(ans.begin(),ans.end());
     return ans;
    }
}