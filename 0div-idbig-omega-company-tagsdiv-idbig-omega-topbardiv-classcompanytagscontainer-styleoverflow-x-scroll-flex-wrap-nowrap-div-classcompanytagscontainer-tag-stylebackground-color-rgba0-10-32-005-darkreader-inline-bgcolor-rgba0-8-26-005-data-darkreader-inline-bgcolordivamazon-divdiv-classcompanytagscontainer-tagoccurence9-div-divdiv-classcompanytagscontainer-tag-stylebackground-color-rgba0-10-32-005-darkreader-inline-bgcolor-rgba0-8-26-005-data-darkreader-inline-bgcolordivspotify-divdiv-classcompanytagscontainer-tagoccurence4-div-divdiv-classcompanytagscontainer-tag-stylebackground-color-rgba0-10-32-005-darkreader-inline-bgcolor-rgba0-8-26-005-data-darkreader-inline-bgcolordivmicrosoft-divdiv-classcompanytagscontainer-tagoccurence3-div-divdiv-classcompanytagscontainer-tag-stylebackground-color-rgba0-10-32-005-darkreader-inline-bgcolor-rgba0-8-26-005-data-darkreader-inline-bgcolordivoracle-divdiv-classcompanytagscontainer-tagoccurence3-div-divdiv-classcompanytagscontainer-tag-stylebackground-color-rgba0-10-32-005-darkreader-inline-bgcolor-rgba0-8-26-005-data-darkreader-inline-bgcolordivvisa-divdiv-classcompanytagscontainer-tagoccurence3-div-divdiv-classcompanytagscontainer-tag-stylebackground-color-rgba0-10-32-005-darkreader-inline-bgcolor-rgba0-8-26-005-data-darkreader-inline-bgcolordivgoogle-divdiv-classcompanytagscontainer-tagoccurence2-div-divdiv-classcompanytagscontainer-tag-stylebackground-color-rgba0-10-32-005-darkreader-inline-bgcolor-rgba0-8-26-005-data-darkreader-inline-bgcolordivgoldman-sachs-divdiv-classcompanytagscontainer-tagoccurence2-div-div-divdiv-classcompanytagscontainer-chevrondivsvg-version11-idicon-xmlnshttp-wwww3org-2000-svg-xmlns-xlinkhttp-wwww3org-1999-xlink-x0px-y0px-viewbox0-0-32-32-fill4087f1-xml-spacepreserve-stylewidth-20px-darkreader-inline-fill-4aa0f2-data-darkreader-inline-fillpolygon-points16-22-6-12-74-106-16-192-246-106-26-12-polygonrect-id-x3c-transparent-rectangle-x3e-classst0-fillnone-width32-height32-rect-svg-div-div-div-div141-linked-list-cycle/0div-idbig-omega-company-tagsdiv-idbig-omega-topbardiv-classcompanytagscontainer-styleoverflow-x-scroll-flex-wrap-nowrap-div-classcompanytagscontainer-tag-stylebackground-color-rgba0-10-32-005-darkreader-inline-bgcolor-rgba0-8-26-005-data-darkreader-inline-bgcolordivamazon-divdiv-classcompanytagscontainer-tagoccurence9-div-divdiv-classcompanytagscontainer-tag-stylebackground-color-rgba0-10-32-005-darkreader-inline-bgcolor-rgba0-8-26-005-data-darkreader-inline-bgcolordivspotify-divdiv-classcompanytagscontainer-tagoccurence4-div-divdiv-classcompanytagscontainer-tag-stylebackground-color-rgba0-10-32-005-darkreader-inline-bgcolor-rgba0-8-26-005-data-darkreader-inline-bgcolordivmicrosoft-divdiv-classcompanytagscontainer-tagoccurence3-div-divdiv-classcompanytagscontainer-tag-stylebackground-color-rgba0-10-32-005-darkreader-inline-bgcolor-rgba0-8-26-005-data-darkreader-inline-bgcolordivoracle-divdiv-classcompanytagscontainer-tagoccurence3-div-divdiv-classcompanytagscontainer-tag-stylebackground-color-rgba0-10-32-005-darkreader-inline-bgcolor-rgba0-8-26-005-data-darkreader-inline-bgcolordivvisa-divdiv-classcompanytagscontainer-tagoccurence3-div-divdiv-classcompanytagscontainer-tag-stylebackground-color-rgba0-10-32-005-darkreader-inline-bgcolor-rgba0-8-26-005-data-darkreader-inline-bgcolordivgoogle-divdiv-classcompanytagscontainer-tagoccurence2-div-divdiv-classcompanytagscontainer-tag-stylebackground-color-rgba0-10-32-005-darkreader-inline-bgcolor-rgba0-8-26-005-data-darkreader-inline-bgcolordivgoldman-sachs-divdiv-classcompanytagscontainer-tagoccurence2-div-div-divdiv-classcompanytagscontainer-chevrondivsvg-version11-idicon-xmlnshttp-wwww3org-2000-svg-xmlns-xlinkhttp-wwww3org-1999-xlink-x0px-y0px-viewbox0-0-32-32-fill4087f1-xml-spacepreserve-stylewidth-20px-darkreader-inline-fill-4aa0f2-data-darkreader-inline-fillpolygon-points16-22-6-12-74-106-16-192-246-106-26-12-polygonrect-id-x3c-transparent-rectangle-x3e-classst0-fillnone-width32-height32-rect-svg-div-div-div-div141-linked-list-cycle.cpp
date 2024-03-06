class Solution {
public:
    bool hasCycle(ListNode *head) {

  if (!head){
      return 0;
  }
     ListNode *slow_pointer = head;
     ListNode *fast_pointer = head;
    

    while ( fast_pointer && fast_pointer->next ){
       
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
         if ( fast_pointer == slow_pointer) {
             return  1;
        }
    }
    return 0;

    }
};