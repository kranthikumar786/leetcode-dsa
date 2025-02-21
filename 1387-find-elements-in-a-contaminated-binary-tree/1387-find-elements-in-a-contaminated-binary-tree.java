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
class FindElements {
   //  TreeNode Lroot = null;
    HashSet<Integer> hashSet ;
     void DFS(TreeNode root, int value){
         if(root == null){
             return ;
         } 
        root.val = value;
        hashSet.add(value);
        if(root.left != null) {
           DFS(root.left , 2*value+1);  
        } 
        if(root.right != null){
            DFS(root.right , 2*value +2);
        } 
       return;
     }
    public FindElements(TreeNode root) {
        hashSet = new HashSet<>();
       DFS(root,0); 
    }
    public boolean find(int target) {
       return hashSet.contains(target);   
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */