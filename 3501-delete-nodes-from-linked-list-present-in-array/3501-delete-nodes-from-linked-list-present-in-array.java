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
    public ListNode modifiedList(int[] nums, ListNode head) {
      HashSet<Integer>hs = new HashSet<>();
      for(int num : nums){
        hs.add(num);
      }
      ListNode dummy = new ListNode(-1);
       dummy.next = head;
      ListNode prev = dummy;
      ListNode cur = head;
       while(cur != null) {
            if(hs.contains(cur.val)){
                prev.next = cur.next;
            } else{
                prev = cur;

            }
            cur = cur.next; 
       }
        return dummy.next; 
    }
}
/**
HashSet<Integer>numVal = new HashSet<>();
      for(int num : nums){
        numVal.add(num);
      }
      ListNode temp = head;
      ListNode prev = new ListNode(-1);
        ListNode in = null;
        while(temp != null){
             if(numVal.contains(temp.val)){
                 in = temp.next;
             } else{
                 prev.next = (in == null ? temp.next : in);
                 prev = prev.next;
                 in = null;
             }
             temp = temp.next; 
        }
        return prev.next;

 */