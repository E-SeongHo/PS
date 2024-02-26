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
    ListNode* mergeThrough(vector<ListNode*>& lists)
    {   // O(N * k) : 205ms, 16.5MB

        ListNode head = ListNode(-1);
        ListNode* current = &head;

        while(true)
        {
            int idx = -1;
            int value = INT_MAX;

            for(int i = 0; i < lists.size(); i++)
            {
                auto& p = lists[i];
                if(p == nullptr) continue;

                if(p->val < value)
                {
                    value = p->val;
                    idx = i;
                }
            } 

            if(idx == -1) break;

            auto& p = lists[idx];
            current->next = p;
            current = current->next;
            p = p->next;
        }
        
        ListNode* ret = head.next;

        return ret;
    }

    ListNode* heapSort(vector<ListNode*>& lists)
    {   // O(NlogN) + O(NlogN) : 19ms, 17.2MB
        auto cmp = [](ListNode* n1, ListNode* n2) -> bool { return n1->val > n2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        
        for(int i = 0; i < lists.size(); i++)
        {   
            ListNode* current = lists[i];
            while(current != nullptr)
            {
                pq.push(current);
                current = current->next;
            }
        }

        ListNode* head = new ListNode(-1);
        ListNode* current = head;

        while(!pq.empty())
        {   
            current->next = pq.top();
            pq.pop();
            current = current->next;
        }
        current->next = nullptr; // important!
        
        return head->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* head = new ListNode(-1);
        ListNode* current = head;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
                current = current->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
                current = current->next;
            }
        }

        if(list1 == nullptr) current->next = list2;
        else current->next = list1;

        return head->next;
    }
    ListNode* devideAndConquer(vector<ListNode*>& lists)
    {   // O(N * logk)
        if(lists.empty()) return nullptr;
        
        // 116ms 
        // for(int i = 0; i < lists.size()-1; i++)
        // {
        //     lists[i+1] = mergeTwoLists(lists[i], lists[i+1]);
        // }

        // 20ms
        int size = lists.size();
        while(size > 1)
        {
            for(int i = 0; i < size/2; i++)
            {
                lists[i] = mergeTwoLists(lists[i], lists[size-i-1]);
            }
            size = (size+1) / 2;
        }

        return lists[0];
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        return devideAndConquer(lists); // O(N * logk)

        return mergeThrough(lists); // O(N * k)
        
        return heapSort(lists); // O(N * logN)
    }
};