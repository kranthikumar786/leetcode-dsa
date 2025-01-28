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


  

/*
root = [1,null,2,3]
Output: [1,2,3]
*/
class Solution {
    //   public void preOrder(TreeNode root, List<Integer>ans){
    //       if(root == null) {return;}
    //      ans.add(root.val);
    //      preOrder(root.left,ans);
    //      preOrder(root.right,ans);
    //   }

public void PreOrder(TreeNode root , List<Integer>ans){
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        while(st.size() > 0) {
             TreeNode currentNode = st.peek();
              st.pop();
              if(currentNode == null)
                 continue;
              ans.add(currentNode.val);
              if(currentNode.right != null) {
                st.push(currentNode.right);
              }
              if(currentNode.left != null) {
                st.push(currentNode.left);
              }
     } }
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        PreOrder(root,ans);
        return ans;
    }
}