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
    int index;
    HashMap<Integer, Integer> hm = new HashMap<>();

    public TreeNode Build(int[] postorder, int s, int e) {
        if (s > e || index < 0) {
            return null;
        }
        int v = postorder[index--];
        TreeNode root = new TreeNode(v);
        root.right = Build(postorder, hm.get(v) + 1, e);
        root.left = Build(postorder, s, hm.get(v) - 1);

        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        for (int i = 0; i < inorder.length; i++) {
            hm.put(inorder[i], i);
        }
        index = inorder.length - 1; 
        return Build(postorder, 0, inorder.length - 1);
    }
}

/**
class Solution {
     int index = 3000;
      HashMap<Integer,Integer>hm =  new HashMap<>();
   public TreeNode Build(int[] postorder, int s, int e){
        if(s > e || index < 0) {return null;}
        int v = postorder[index--];
        TreeNode root = new TreeNode(v);
        root.left  = Build(postorder,s,hm.get(v)-1);
        root.right = Build(postorder,hm.get(v)+1, e);
       return root;
   }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        for(int i = 0 ; i < inorder.length ; i++) {
             hm.put(inorder[i],i);
        } 
        index = inorder.length-1;
       return Build(postorder,0,inorder.length-1);  
    }
}
 */