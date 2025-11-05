class Solution {
    void inorder(TreeNode root, List<Integer> arr) {
        if (root == null) return;
        inorder(root.left, arr);
        arr.add(root.val);
        inorder(root.right, arr);
    }

    TreeNode newroot(List<Integer> arr, int s, int e) {
        if (s > e) return null;
        int m = (s + e) / 2;
        TreeNode root = new TreeNode(arr.get(m));
        root.left = newroot(arr, s, m - 1);
        root.right = newroot(arr, m + 1, e);
        return root;
    }

    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        
        List<Integer> arr = new ArrayList<>();
        inorder(root, arr);
        
        if (!arr.contains(key)) return root; 
        
        arr.remove(Integer.valueOf(key)); 
        
        return newroot(arr, 0, arr.size() - 1);
    }
}
