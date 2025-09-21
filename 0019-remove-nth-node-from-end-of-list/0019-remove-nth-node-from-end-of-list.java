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
    public ListNode removeNthFromEnd(ListNode head, int n) {
     ListNode dummy = new ListNode(0,head);
     ListNode first = dummy, second = dummy;
       for(int i = 0 ; i <=n ; i++) {
             first = first.next;
       }
       while(first != null) {
          first = first.next;
          second = second.next;
       } 
        second.next = second.next.next;
        return dummy.next;
    }
}
/**

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
 /*
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
       int totalValue = 0;
       ListNode temp  = head;
       while( temp != null ) {
              totalValue++;
              temp = temp.next;
        }
     ListNode temp1 = head;
      for(int i = 0 ; i < totalValue ;i++) {
          if( i == n-1) {
             head = head.next.next;
              return temp1;
          }
          head = head.next;
      } 
     return temp1;


int totalCnt = 0;
     ListNode temp = head;
     while(temp != null) {
        totalCnt++;
        temp = temp.next;
       }
      if(n == totalCnt) {
           return head.next;
      }
       temp = head;
      for(int i = 1; i < totalCnt - n ; i++) {
             temp = temp.next;
      } 
        temp.next = temp.next.next;
       // above is assigning , not moving
     return head;


        /**
        1  find the no.of elemtns presen tin the list : 
        2  then do remove the nth node:
        -----------------------
        recesvieapproach :
          1 2 3 4 5 :
             cnt++;
     
      -------------------
         */