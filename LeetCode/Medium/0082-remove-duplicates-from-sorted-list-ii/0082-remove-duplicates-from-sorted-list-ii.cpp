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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* previous = nullptr;
        ListNode* current = head;
        int dup = -1000;
        
        while(current != nullptr)
        {
            if(current->next != nullptr)
            {   
                if(current->val == current->next->val)
                    dup = current->val;
            }
            if(current->val == dup)
            {
                current = current->next;
                if(previous == nullptr) head = current;
                else previous->next = current;
            }
            else
            {
                previous = current;
                current = current->next;
            }
            
        }
        return head;
    }
};