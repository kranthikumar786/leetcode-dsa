/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
       if(root == null) {
          return root;
       }
       Queue<Node> Q = new LinkedList<>();
      Q.add(root);
       while (Q.size() > 0) {
          Node cNode = null;
          int levelSize = Q.size();
         for(int i = levelSize -1 ; i >= 0 ;i--) {  
            Node cNodeI = Q.poll();
            cNodeI.next = cNode;
            cNode = cNodeI;
            if(cNodeI.right != null) {
                Q.add(cNodeI.right);
            }
            if(cNodeI.left != null) {
                Q.add(cNodeI.left);
            }
         }
         }
         return root;
       
    }
}