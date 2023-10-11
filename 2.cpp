class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* emptyNode = new ListNode(0);
        ListNode* res = emptyNode;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {   
            int n1 = (l1 != nullptr) ? l1->val : 0;
            int n2 = (l2 != nullptr) ? l2->val : 0; 

            int sum = n1 + n2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* currentDigit = new ListNode(digit);
            res->next = currentDigit;
            res = res->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        
        res = emptyNode->next; 
        delete emptyNode;
        return res;
    }
};