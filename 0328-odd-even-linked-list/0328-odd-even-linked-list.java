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
    public ListNode oddEvenList(ListNode head) {
      if(head == null) {return null;}
      ArrayList<Integer>even = new ArrayList<>();
      ArrayList<Integer>odd = new ArrayList<>();
       ListNode temp = head;
       int index = 1;
       while(temp != null) {
            if(index %2 == 1){
                 odd.add(temp.val);
            }else{
                 even.add(temp.val);
            }
            index++;
            temp = temp.next;
       }
     ListNode reOrderHead = new ListNode(0);
     ListNode dummy = reOrderHead;
     for(int value : odd){
        dummy.next = new ListNode(value);
        dummy = dummy.next;
      }
      for(int value : even){
        dummy.next = new ListNode(value);
        dummy = dummy.next;
      }   

  
      return reOrderHead.next;
        /**
          1, 2,     3 ,4 ,5 :
             even  odd
           // tempNodeforEven 2's next value  
            tempNodeforOdd : 3' next value :
            1's next should attach to 3: 
            3' next should get attach to 2's next:
          1 3 5 2 4 
        evenPtr , oddPtr :
         */
    }
}
/**

MisUndestood the Probelm Statement
 ArrayList<Integer>even = new ArrayList<>();
        ArrayList<Integer>odd = new ArrayList<>();
       ListNode temp = head;
        boolean evenFlag = false;
        if(temp!= null  && temp.val%2 == 0) {
           evenFlag = true;
        }
       while(temp != null) {
           if(temp.val %2 == 0) {
              even.add(temp.val);
           }else{
            odd.add(temp.val);
           }
           temp = temp.next;
       }
  ListNode reOrderHead = new ListNode();
      if(evenFlag) {
          ListNode reOrdertemp = new ListNode();
          reOrderHead = reOrdertemp;
          for(int i = 0 ; i < even.size() ;i++) {
               reOrdertemp = new ListNode(even.get(i));
               reOrdertemp = reOrdertemp.next;
          }
          for(int i = 0; i < odd.size();i++){
            reOrdertemp = new ListNode(odd.get(i));
               reOrdertemp = reOrdertemp.next;
          }
      } else{
          ListNode reOrdertemp = new ListNode();
          reOrderHead = reOrdertemp;
          for(int i = 0; i < odd.size();i++){
            reOrdertemp = new ListNode(odd.get(i));
            System.out.println(odd.get(i));
               reOrdertemp = reOrdertemp.next;
          }
            for(int i = 0 ; i < even.size() ;i++) {
               reOrdertemp = new ListNode(even.get(i));
               System.out.println(even.get(i));
               reOrdertemp = reOrdertemp.next;
          }
      }
      return reOrderHead;
 */