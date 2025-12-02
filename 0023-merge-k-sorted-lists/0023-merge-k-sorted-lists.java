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
     class Pair{
        int val;
        ListNode node;
        Pair(int val,ListNode node){
            this.val = val;
            this.node = node;
        }
     }  
    public ListNode mergeKLists(ListNode[] lists) {
       PriorityQueue<Pair>minHeap = new PriorityQueue<>((a,b) ->(a.val-b.val));
       ListNode dummy = new ListNode(-1);
       ListNode tail = dummy;
       int n = lists.length;
       for(int i = 0 ; i < n  ; i++){
            if(lists[i] != null)
             minHeap.add(new Pair(lists[i].val,lists[i]));
       }
       while(minHeap.size() > 0) {
         Pair p = minHeap.poll();
         tail.next = p.node;
         if(p.node.next != null){
            minHeap.add(new Pair(p.node.next.val,p.node.next));
         } 
          tail = tail.next;
       } 
    return dummy.next;
        /**
         [1,4,5]
         [1,3,4]
         [2,6]
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

       //  create an array of totalNo.of elemts:
          then sort in ascending orde rthen , craetar an linkedlist 
         ===================================================
        int n = lists.length;
        ListNode head = null;
        ListNode l1 = lists[0];
        ListNode prev = new ListNode(-1);
        for(int i = 1; i < n ; i++) {
            ListNode l2 = lists[i];
             while(l1 != null && l2 != null) {
                    if(l1.val <= l2.val){
                         if(head == null) {
                            head = l1;
                         }
                      prev.next = l1;
                      prev = l1;
                      l1 = l1.next; 
                    } else{
                        prev.next = l2;
                        prev = l2;
                        l2 = l2.next;
                    }
             }
             while(l2 != null ){
               prev.next = 
                l1.next = l2;
                l2 = l2.next;
                l1 = l1.next;
                
             }
        }
         */

    }
}