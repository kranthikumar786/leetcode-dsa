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
     while( Q.size() > 0) {
        int levelSize = Q.size();
              Node currentNode = null;
         for(int i = levelSize -1  ; i >= 0 ; i--) {
             Node currentNode1 = Q.poll();
               if(currentNode1 == null)
                    continue;
              currentNode1.next = currentNode;
              currentNode = currentNode1;
           if(currentNode1.right != null){
            Q.add(currentNode1.right);
           } 
            if(currentNode1.left != null){
            Q.add(currentNode1.left);
           }
         }}
      return root;   
     
    }
}



/**


class Solution {
    public Node connect(Node root) {
    Queue<Node> Q = new LinkedList<>();
    Q.add(root);
     while( Q.size() > 0) {
        int levelSize = Q.size();
   Node currentNode1 = null; Node currentNode2 = null;
         for(int i = 0 ; i < levelSize ; i++) {
            if(Q.size() >= 2) {
              if(i == 0 ){
               currentNode1 = Q.poll();
               currentNode2 = Q.poll();} else{
                currentNode1 = currentNode2;
                currentNode2 = Q.poll();
               }
               currentNode1.next = currentNode2;
               if(Q.size() == 0) {
                currentNode2.next = null;
                currentNode1 = currentNode2;
               }
            } else{
                currentNode1 = Q.poll();
                if(currentNode1 == null)
                   continue;
               currentNode1.next = null;    
            }
           if(currentNode1 != null && currentNode1.left != null){
            Q.add(currentNode1.left);
           } 
           if(currentNode1 != null && currentNode1.right != null){
            Q.add(currentNode1.right);
           } 
         }}
      return root;   
     
    }
}
 */