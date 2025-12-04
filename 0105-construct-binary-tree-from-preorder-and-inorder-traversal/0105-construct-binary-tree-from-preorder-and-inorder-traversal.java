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
    HashMap<Integer,Integer>hm ;
    int index = 0;
    public TreeNode TreeCons(int[] preorder,int left, int right){
        //  if(left >= preorder.length || right < 0  || index >= preorder.length) return null;
          if(left > right) return null;
         TreeNode node = new TreeNode(preorder[index]);
         int rootIndex = hm.get(preorder[index++]);
         node.left =  TreeCons(preorder,left,rootIndex-1);
         node.right = TreeCons(preorder,rootIndex+1,right); 
     return node;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
         hm = new HashMap<>();
        for(int i = 0 ; i < inorder.length;i++){
              hm.put(inorder[i],i);
        }
     return TreeCons(preorder,0,preorder.length-1); 
    }
}