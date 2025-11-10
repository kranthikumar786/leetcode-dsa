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
   
     HashMap<Integer,Integer>hm = new HashMap<>();
     int index = 0;
    public TreeNode build(int [] pre,int s, int e){
         if(s > e) {return null;}
          int val = pre[index++]; 
        TreeNode root = new TreeNode(val);
         root.left = build(pre,s,hm.get(val)-1);
         root.right = build(pre,hm.get(val)+1,e);
         return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
       for(int i = 0 ;i < inorder.length; i++) {
           hm.put(inorder[i],i);
       } 
     return build(preorder,0,preorder.length-1);
    }
}