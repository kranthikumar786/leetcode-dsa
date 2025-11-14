/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
     ListNode slow = head;
     ListNode fast = head;
     boolean cyelDetected = false;
      while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast ){
                 slow = head;
                 cyelDetected = true;
                 break;
            }
      }
      if(!cyelDetected) return null;
       while(slow != fast) {
           slow = slow.next;
           fast = fast.next;
       }
    return slow;
    }
}
/**
HashSet<ListNode>hs = new HashSet<>();
     ListNode temp = head;
     while(temp != null) {
          if(hs.contains(temp)) return temp;
         hs.add(temp);
         temp = temp.next; 
     }
 */