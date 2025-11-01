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
    public boolean isPalindrome(ListNode head) {
     ListNode slow = head, faster = head;
     while(faster != null && faster.next != null) {
            slow = slow.next;
            faster = faster.next.next;
     }   
  
     ListNode prev = null;
     //ListNode cur = slow;
       while(slow != null) {
            ListNode Next =  slow.next;
            slow.next = prev;
            prev = slow;
            slow = Next; 
       }
        while(prev != null){
               if(head.val != prev.val){
                  return false;
               }
               head = head.next;
               prev = prev.next; 
        }
    return true;
    }
}