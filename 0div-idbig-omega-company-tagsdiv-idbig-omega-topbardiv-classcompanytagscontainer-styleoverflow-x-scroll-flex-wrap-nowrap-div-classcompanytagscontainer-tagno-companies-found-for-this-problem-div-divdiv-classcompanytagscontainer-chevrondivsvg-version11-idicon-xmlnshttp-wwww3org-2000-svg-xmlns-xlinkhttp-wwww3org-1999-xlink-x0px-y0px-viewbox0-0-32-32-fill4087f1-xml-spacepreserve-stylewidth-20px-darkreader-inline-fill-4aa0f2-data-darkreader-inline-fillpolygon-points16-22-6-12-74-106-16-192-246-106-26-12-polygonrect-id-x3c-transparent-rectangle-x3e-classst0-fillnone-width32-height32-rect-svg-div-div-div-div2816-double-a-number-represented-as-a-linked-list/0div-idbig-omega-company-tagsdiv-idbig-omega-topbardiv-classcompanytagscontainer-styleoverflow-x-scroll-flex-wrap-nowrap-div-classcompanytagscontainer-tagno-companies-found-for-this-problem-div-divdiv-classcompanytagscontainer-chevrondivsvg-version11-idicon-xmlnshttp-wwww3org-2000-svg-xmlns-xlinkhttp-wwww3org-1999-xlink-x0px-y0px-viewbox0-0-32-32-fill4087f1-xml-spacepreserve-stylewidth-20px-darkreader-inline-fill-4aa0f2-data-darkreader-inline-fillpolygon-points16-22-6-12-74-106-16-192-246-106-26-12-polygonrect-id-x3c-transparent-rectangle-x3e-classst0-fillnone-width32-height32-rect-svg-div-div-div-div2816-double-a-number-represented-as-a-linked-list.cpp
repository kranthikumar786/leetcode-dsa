/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
      /*
      unsigned long long  num = 0 ;
      ListNode* node = head;
          while (node) {
               num = num*10  + (node->val); 
               node = node->next;
          }
        if(num == 0) {
             return head;
        }
        num *= 2;
        cout<< num <<" ";
       ListNode* AfterHead = NULL; 
         while ( num ) {        
             ListNode * node = new  ListNode(num%10);
              
              if ( !AfterHead ) {
                   AfterHead = node;
              } else {
                   node ->next = AfterHead;   
                  AfterHead = node; 
              }
           num /= 10;   
         }
       return AfterHead; 
       
       */
        
         ListNode* prev = NULL;
        ListNode* ret = head;
        while(head){
            int tmp = head->val + head->val;
            head->val = tmp%10;
            if (tmp/10){
                if (!prev){
                    ListNode* node = new ListNode(1, head);
                    ret = node;
                }
                else prev->val++;
            }
            prev = head;
            head =  head->next;
        }
        return ret;
    
    }
};