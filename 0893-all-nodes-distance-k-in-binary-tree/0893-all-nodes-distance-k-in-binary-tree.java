class Solution {
    public void buildchildParentMap(TreeNode root, HashMap<TreeNode, TreeNode> childParent) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node.left != null) {
                q.add(node.left);
                childParent.put(node.left, node);
            }
            if (node.right != null) {
                q.add(node.right);
                childParent.put(node.right, node);
            }
        }
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        HashMap<TreeNode, TreeNode> childParent = new HashMap<>();
        buildchildParentMap(root, childParent);
        HashMap<TreeNode, Boolean> Visited = new HashMap<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(target);
        Visited.put(target, true);
        int level = 0;

        while (!q.isEmpty()) {
            int size = q.size();
            if (level == k) break;
            level++;
            for (int i = 0; i < size; i++) {
                TreeNode polled = q.poll();
                if (polled.left != null && !Visited.containsKey(polled.left)) {
                    Visited.put(polled.left, true);
                    q.add(polled.left);
                }
                if (polled.right != null && !Visited.containsKey(polled.right)) {
                    Visited.put(polled.right, true);
                    q.add(polled.right);
                }
                if (childParent.containsKey(polled) && !Visited.containsKey(childParent.get(polled))) {
                    TreeNode parent = childParent.get(polled);
                    Visited.put(parent, true);
                    q.add(parent);
                }
            }
        }

        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) ans.add(q.poll().val);
        return ans;
    }
}
