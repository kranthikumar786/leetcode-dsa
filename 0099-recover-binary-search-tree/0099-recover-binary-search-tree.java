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
    TreeNode first, middle, last, prev;
    public void inorder(TreeNode cur) {
        if (cur == null) return;
        inorder(cur.left);
        if (prev != null && cur.val < prev.val) {
            if (first == null) {
                first = prev;
                middle = cur;
            } else {
                last = cur;
            }
        }
        prev = cur;
        inorder(cur.right);
    }
    public void recoverTree(TreeNode root) {
        prev = null;
        inorder(root);
        if (first != null && last != null) {
            int temp = first.val;
            first.val = last.val;
            last.val = temp;
        } else if (first != null && middle != null) {
            int temp = first.val;
            first.val = middle.val;
            middle.val = temp;
        }
    }
}
