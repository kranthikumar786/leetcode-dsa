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
class BSTIterator {
     private  TreeNode curRoot;
     private TreeNode nextNode;
    public BSTIterator(TreeNode root) {
        curRoot = root;
        nextNode = findNext();
    }
    public int next() {   
      int t = nextNode.val;
      nextNode = findNext();
      return t;
    }
    public boolean hasNext() {
       return nextNode != null;    
    }
    public TreeNode findNext(){
        TreeNode node = curRoot;
         while(node != null) {
             if(node.left == null) {
                 curRoot = node.right;
                 return node;
             } else{
                 TreeNode pre = node.left;
                  while(pre.right != null && pre.right != node){
                         pre = pre.right;
                  }
                   if(pre.right == null) {
                       pre.right = node;
                       node = node.left;
                   } else{
                      pre.right = null;
                       curRoot = node.right;
                       return node;
                   } 
             }
         }
        return null; 
    } 
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */

 /**
 class BSTIterator {
   TreeNode cur;
    public BSTIterator(TreeNode root) {
       cur = root;
      pushAll(cur);  
    }
    public int next() {
        int t = cur.val;
      pushAll(cur,cur.right);
      return t;  
    }
    public boolean hasNext() {
      return cur.right != null ;  
    }
  public void pushAll(TreeNode cur){
           while(cur != null){ 
          if(cur.left == null) {
               cur = cur.right;  
         } else{
            TreeNode rightMost = cur.left;
         while(rightMost != null && rightMost != cur) {
              rightMost = rightMost.right;
         }
         if(rightMost == null){
            rightMost = cur;
            cur = cur.left;
         } else{
               cur = cur.right;
              rightMost = null; 
         }
          }
    }
}
  */