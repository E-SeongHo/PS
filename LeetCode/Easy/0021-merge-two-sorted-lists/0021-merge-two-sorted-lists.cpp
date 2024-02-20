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
    ListNode* iterative(ListNode* list1, ListNode* list2)
    {
        ListNode head = ListNode();
        ListNode* current = &head;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        if(list1 == nullptr)
        {
            while(list2 != nullptr)
            {
                current->next = list2;
                list2 = list2->next;

                current = current->next;
            }
        }
        else
        {
            while(list1 != nullptr)
            {
                current->next = list1;
                list1 = list1->next;

                current = current->next;
            }
        }

        return head.next;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // recursive approach
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
        }

        if(list1->val <= list2->val) return list1;
        else return list2;
    }
};