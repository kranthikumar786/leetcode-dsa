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
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int numOfNodes = preorder.length;
        int[] indexInPostorder = new int[numOfNodes + 1];

        // Populate the index array with postorder values
        for (int i = 0; i < numOfNodes; i++) {
            indexInPostorder[postorder[i]] = i;
        }

        return constructTree(0, numOfNodes - 1, 0, preorder, indexInPostorder);
    }

    private TreeNode constructTree(int preStart, int preEnd, int postStart, int[] preorder, int[] indexInPostorder) {
        if (preStart > preEnd) return null;

        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        int leftRoot = preorder[preStart + 1];
        int numOfNodesInLeft = indexInPostorder[leftRoot] - postStart + 1;

        TreeNode root = new TreeNode(preorder[preStart]);

        root.left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
                                  postStart, preorder, indexInPostorder);

        root.right = constructTree(preStart + numOfNodesInLeft + 1, preEnd,
                                   postStart + numOfNodesInLeft, preorder, indexInPostorder);

        return root;
    }
}
