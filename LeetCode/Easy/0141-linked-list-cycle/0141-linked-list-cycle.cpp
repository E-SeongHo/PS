/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 1. naive : using set
        
        // 2. O(1) space complexity
        //  Floyd tortoise and hare (two pointer)
        if(head == nullptr) return false;
        
        ListNode* tortoise = head;
        ListNode* hare = head;
        
        while(tortoise != nullptr && hare->next != nullptr)
        {   
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(hare == nullptr) return false;
            
            if(tortoise == hare) return true;
        }
        
        return false;
    }
};