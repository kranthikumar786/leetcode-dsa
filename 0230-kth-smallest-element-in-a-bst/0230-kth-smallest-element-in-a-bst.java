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
    
    public int kthSmallest(TreeNode root, int k) {
      TreeNode cur = root;
       while(cur != null){
            if(cur.left == null){
                k--;
               if(k == 0)return cur.val;
               cur = cur.right;
            } else{
                   TreeNode pre = cur.left;
                     while(pre.right != null && pre.right != cur){
                           pre = pre.right;
                     }
                      if(pre.right == null) {
                          pre.right = cur;
                           cur = cur.left;
                      } else{
                          k--;
                           if(k == 0) return cur.val;
                           pre.right = null;
                            cur = cur.right;
                      }
            }
       }
     return 0;
    }
}
/**

int ans = -1;
    int cnt = 0;
    boolean found = false;
      void inOrder(TreeNode root, int k){
          if(root == null) return ;

          inOrder(root.left,k);
           if(found) return;
          cnt++;
          
          if(cnt == k && ans == -1){
               ans = root.val;
               found = true;
               return; 
          }
          inOrder(root.right,k);
      }

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and 
you need to find the kth smallest frequently, how would you optimize?
  Using augmentedBST : with structur of  {value,left,right,size} : 
 
  class TreeNode{
    int val;
    TreeNode left ,right;
    int size; // store the number of nodes in substree root
     TreeNode(int val){
        this.val = val;
        this.size = 1;
     }

  }
  class AugmentedBST {
       TreeNode root;
       private int size(TreeNode node){
          return node == null ? 0 : node.size;
       }
       private TreeNode insert(TreeNode node ,int val){
          if(node == null)return new TreeNode(val);
           if(val < node.val) {
            node.left = insert(node.left,val);
           } else
              node.right = insert(node.right,val); 
         node.size = 1+ size(node.left) + size(node.right);
         return node;
       }  
       private TreeNode delete(TreeNode node, int val){
           if(node == null) return null;
           if(val < node.val){
               root.left = delete(node.left,val);
           } else if(val > node.val){
              node.right = delete(node.right,val);

           } else{
              if(node.left == null) return node.right;
              if(node.right == null) return node.left;
               TreeNode successorParent = node;
              TreeNode successor = node.right;
              while (successor.left != null) {
                     successorParent = successor;
                    successor = successor.left;
                  }

                   // Copy successor value
                  node.val = successor.val;

               // Delete successor directly
                    if (successorParent.left == successor)
                     successorParent.left = successor.right;
                   else
                     successorParent.right = successor.right;
           }

         node.size = 1 + size(node.left) + size(node.right);
          return node;  
       }

      private int kthSmallest(TreeNode node, int k){
          int leftSize = size(node.left);
          if(k == leftSize + 1){
              return node.val;
          } else if(k <= leftSize){
             return kthSmallest(node.left,k);
          } else
            return kthSmallest(node.right,k-leftSize-1);
      }
       
     public void insert(int val){
         root = insert(root,val);
     }  
     public void delete(int val){
        root = delete(root,val);
     }
     public int kthSmallest(int k){
          if(root == null || k <= 0 || k > size(root)){
             throw new IllegalArgumentException("Invalid Input");
          }
         return kthSmallest(root,k); 
     }

  } 

   






 */