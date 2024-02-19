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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(-1);
        ListNode* current = head;

        bool carry = false;
        while(l1 != nullptr || l2 != nullptr)
        {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;

            int sum = val1 + val2;
            if(carry) sum++;

            carry = sum >= 10 ? true : false;
            sum = sum % 10;

            ListNode* node = new ListNode(sum);

            current->next = node;
            current = node;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }

        if(carry) current->next = new ListNode(1);

        return head->next;
    }
};