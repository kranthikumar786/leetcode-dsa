/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
     ListNode prev = null;
     ListNode next = null;
     ListNode cur = head;
    while(cur != null) {
        next = cur.next;
         cur.next = prev;
         prev = cur;
        cur = next;
    }
    return prev;
    }
}
/**

 [1|n]->[2|n] :->[3|n]:
  p       c      n 
1->2->   3->4->5:
  ->3->2->1
  p
1<-2<3-<4-<5: 

[1|n]<-[2|n]<-[3|n]:

 */