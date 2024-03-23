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
    ListNode* findMid(ListNode* head) {
        ListNode *slow = head, *fast = head;
        ListNode* prev;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        return slow;
    }

    ListNode* reverseList(ListNode* mid) {
        ListNode *prev = nullptr, *curr = mid;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void mergeLists(ListNode *list1, ListNode *list2) {
        ListNode *currEnd = nullptr, *curr = list1, *adder = list2;

        while(curr && adder) {
            ListNode *currNext = curr->next;
            ListNode *adderNext = adder->next;

            curr->next = adder;
            adder->next = currNext;
            currEnd = adder;

            curr = currNext;
            adder = adderNext;
        }

        if(adder) currEnd->next = adder;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *mid = findMid(head);
        ListNode *revHead = reverseList(mid);
        mergeLists(head, revHead);
        return;
    }
};