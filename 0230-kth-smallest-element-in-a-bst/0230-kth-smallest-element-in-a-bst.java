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
//    ArrayList<Integer> sorted = new ArrayList<>();
//    void inorderTravesal(TreeNode root) {
//        if(root != null) {
//          inorderTravesal(root.left);
//          sorted.add(root.val);
//          inorderTravesal(root.right);
//        }
//    }
// inorderTravesal(root);
          //return sorted.get(k-1);
        /**
        BST inorder travesal gives the sorted order elements :
         so stor ein in array , then find the K-1 elemnte return it :
       TC: O(n)
       SC: O(n)
         **/
     private int count;
    private int ans;
    
    public int kthSmallest(TreeNode root, int k) {
        count = 0;       // reset for each test case
        ans = -1;
        inOrderTraversal(root, k);
        return ans;
    }

    private void inOrderTraversal(TreeNode root, int k) {
        if (root == null) return;

        inOrderTraversal(root.left, k);

        count++;
        if (count == k) {
            ans = root.val;
            return;
        }

        inOrderTraversal(root.right, k);
    }
}