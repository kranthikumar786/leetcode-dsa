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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
      ListNode ans = new ListNode(0);
      ListNode ans1 = ans;
      ListNode t1 = l1;
      ListNode t2 = l2;
      int rem = 0;
        while(t1 != null || t2 != null) {
               int sum = 0;
               if(t1 != null){
                 sum += t1.val;
                  t1 = t1.next;
               }
               if(t2 != null) {
                  sum += t2.val;
                    t2 = t2.next;
               }
           ans.next = new ListNode((sum+rem)%10);
            rem = (sum + rem )/10; 
            ans = ans.next;
        }
        if(rem > 0){
            ans.next = new ListNode(rem);
        }
      return ans1.next;
    }
}