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
    // Follow Up : Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
    void print(ListNode* head)
    {
        if(head == nullptr) cout << "nullptr" << endl;
        while(head != nullptr)
        {
            cout << head->val << "-> ";
            head = head->next;    
        }
    }
    ListNode* getMid(ListNode* head)
    {
        int cnt = 0;
        ListNode* current = head;
        ListNode* follow = head;
        while(current->next != nullptr)
        {
            current = current->next;
            if(++cnt % 2 == 0) follow = follow->next;
        }
        
        ListNode* mid = follow->next;
        follow->next = nullptr;
        return mid;
    }
    ListNode* merge(ListNode* h1, ListNode* h2)
    {  
        ListNode* head = nullptr;
        if(h1->val <= h2->val)
        {
            head = h1;
            h1 = h1->next;
        }
        else
        {
            head = h2;
            h2 = h2->next;
        }

        ListNode* current = head;
        while(h1 != nullptr && h2 != nullptr)
        {
            if(h1->val <= h2->val)
            {
                current->next = h1;
                h1 = h1->next;
            }
            else
            {
                current->next = h2;
                h2 = h2->next;
            }
            current = current->next;
        }

        ListNode* leftover = h1 != nullptr ? h1 : h2;
        while(leftover != nullptr)
        {
            current->next = leftover;
            leftover = leftover->next;
            current = current->next;
        }
        return head;
    }
    void mergeSort(ListNode** headPointer)
    {
        ListNode* head = *headPointer;
        if(head->next == nullptr) return;

        ListNode* mid = getMid(head);
        mergeSort(&head);
        mergeSort(&mid);
        *headPointer = merge(head, mid);
    }
    ListNode* sortList(ListNode* head) 
    {   
        if(head == nullptr) return head;

        mergeSort(&head);
        return head;
    }
};