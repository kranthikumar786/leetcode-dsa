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
    
    public TreeNode createBst(int arr[],int s, int e){
          if(s > e) return null;
          TreeNode root = new TreeNode(arr[s]);
          int lastIndex =e+1;
          for(int j = s+1; j <= e ;j++) {
              if(arr[j] > arr[s]){
                   lastIndex = j;
                   break;
              }
          }
           root.left = createBst(arr,s+1,lastIndex-1);
           root.right = createBst(arr,lastIndex,e);
           return root;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
     return createBst(preorder,0,preorder.length-1);   
    }
}
/**

public TreeNode createBst(int[] arr, int s, int e){
          if(s > e) return null;
          if(s == e) {return new TreeNode(arr[s]);}
           int lastIndex = -1;
                for(int j = s+1; j < e; j++) {
                       if(arr[j] > arr[s]){
                           break;
                       }
                       lastIndex = j;
                }
          TreeNode root = new TreeNode(arr[s]);
          root.left = createBst(arr,s+1,lastIndex);
          root.right = createBst(arr,lastIndex+1,e); 
    return root;
    }
 */