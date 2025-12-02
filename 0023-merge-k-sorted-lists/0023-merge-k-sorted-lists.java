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
    public ListNode mergeKLists(ListNode[] lists) {
        
        int n = lists.length;
        // ArrayList<Integer>arr = new ArrayList<>();
        PriorityQueue<Integer>minHeap = new PriorityQueue<>();
        for(int i = 0; i < n ;i++) {
              ListNode node = lists[i]; 
                    while(node != null){
                   // arr.add(node.val);
                   minHeap.add(node.val);
                   node = node.next;
             }
        }
        //Collections.sort(arr);
        ListNode head = null, temp =null;
        //for(int i = 0 ; i < arr.size(); i++) {
          while(minHeap.size() > 0){
              if(head == null){
                 head = new ListNode(minHeap.poll());
                 temp = head;
              } else{
                temp.next = new ListNode(minHeap.poll());
                temp = temp.next;
              }
           }
      return head;

        /**
         [1,4,5]
         [1,3,4]
         [2,6]

       //  create an array of totalNo.of elemts:
          then sort in ascending orde rthen , craetar an linkedlist 
         */

    }
}