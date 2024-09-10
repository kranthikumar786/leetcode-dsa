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
  int gcd(int a , int b) {
       if(b == 0) {return a;}
        while ( b > 0) {
         int t = b ;
            b = a%b;
            a = t; 
        } 
       return a;
        }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* travesal = head;
      while (travesal && travesal->next) { 
         int gcdv = gcd(travesal->val,travesal->next->val);
         ListNode* NewNode = new  ListNode(gcdv);
             NewNode->next =travesal->next;
            travesal->next = NewNode;
            travesal = NewNode->next; 
         }
 return head;

    }
};