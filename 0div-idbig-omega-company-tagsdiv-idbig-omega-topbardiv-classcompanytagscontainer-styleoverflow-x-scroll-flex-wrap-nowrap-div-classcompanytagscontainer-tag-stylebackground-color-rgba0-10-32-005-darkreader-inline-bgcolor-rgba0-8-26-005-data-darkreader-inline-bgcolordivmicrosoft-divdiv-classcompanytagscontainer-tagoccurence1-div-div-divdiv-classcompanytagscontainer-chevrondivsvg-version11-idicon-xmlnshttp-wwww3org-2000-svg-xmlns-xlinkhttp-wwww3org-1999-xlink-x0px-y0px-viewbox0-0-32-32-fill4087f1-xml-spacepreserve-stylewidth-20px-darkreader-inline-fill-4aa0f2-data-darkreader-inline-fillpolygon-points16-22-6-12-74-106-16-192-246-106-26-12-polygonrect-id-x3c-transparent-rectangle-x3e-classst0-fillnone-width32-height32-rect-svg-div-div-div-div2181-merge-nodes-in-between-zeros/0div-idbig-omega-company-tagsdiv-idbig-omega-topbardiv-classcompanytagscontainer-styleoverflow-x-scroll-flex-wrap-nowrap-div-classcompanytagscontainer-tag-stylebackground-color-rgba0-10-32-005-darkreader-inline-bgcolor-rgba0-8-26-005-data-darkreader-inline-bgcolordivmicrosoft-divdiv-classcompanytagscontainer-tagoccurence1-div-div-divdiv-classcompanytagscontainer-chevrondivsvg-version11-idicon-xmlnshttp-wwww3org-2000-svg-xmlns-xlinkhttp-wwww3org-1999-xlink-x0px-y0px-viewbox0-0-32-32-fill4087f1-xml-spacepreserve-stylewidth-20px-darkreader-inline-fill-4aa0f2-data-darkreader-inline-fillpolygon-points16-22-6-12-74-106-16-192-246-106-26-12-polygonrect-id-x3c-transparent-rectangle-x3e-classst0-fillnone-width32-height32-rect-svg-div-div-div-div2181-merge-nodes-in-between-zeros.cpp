class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       
        ListNode* rtn = nullptr;
        
        ListNode* end_rtn = nullptr;
        
        int sum = 0;
        
        head = head->next;
        
        while (head != nullptr)
        {
            if (head->val == 0)
            {
                ListNode* node = new ListNode(sum);
                
                if (rtn == nullptr)
                    rtn = end_rtn = node;
                else
                {
                    end_rtn->next = node;
                    end_rtn = end_rtn->next;
                }
                
                // reset the sum value
                sum = 0;
            }
            else
                sum += head->val;
            
            head = head->next;
        }
        
             return rtn;
    }
};