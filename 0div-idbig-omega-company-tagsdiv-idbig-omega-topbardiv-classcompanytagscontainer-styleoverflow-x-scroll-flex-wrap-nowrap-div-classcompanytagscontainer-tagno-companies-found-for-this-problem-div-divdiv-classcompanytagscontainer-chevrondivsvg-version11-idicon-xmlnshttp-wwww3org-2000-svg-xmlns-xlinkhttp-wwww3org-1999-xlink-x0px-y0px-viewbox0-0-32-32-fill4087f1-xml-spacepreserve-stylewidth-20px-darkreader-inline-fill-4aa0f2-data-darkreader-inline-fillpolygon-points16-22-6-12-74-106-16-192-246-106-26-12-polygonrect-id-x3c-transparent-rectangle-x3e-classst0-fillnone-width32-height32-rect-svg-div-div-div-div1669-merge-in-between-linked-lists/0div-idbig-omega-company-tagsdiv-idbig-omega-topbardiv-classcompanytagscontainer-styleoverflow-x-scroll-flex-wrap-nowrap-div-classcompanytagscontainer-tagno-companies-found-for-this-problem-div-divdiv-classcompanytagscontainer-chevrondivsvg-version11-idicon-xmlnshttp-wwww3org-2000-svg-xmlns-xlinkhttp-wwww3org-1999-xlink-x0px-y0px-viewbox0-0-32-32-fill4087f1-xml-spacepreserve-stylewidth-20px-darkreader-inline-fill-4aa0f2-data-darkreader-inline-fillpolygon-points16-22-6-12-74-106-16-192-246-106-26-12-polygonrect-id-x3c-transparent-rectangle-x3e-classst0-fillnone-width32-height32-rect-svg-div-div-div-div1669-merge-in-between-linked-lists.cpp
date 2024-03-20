class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = nullptr;
        ListNode* end = list1;

        for (int index = 0; index < b; index++) {
            if (index == a - 1) {
                start = end;
            }
            end = end->next;
        }
        start->next = list2;

        ListNode* tail = list2;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = end->next;
        end->next =  nullptr;

        return list1;
    }
};