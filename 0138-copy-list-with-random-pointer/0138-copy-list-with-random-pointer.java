/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node cur = head;
        HashMap<Node,Node>cloned = new HashMap<>(); // oorginalNode, clonedNode
          while( cur != null) {
              cloned.put(cur, new Node(cur.val));
               cur = cur.next;
          }
          cur = head;
            while(cur != null) {
                 Node ClonedNode = cloned.get(cur);
                 ClonedNode.next = cloned.get(cur.next);
                 ClonedNode.random =  cloned.get(cur.random);
                 cur = cur.next;
            }
          return cloned.get(head);
    }
}