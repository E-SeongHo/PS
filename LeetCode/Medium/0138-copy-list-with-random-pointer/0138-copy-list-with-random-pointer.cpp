/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copy_naive(Node* head)
    {
        if(head == nullptr) return nullptr;
        
        Node* copyHead = new Node(head->val);
        Node* copyCurrent = copyHead;
        Node* current = head;
        
        while(current->next != nullptr)
        {
            Node* newNode = new Node(current->next->val);
            copyCurrent->next = newNode;
            
            copyCurrent = copyCurrent->next;
            current = current->next;
        }
        
        current = head;
        copyCurrent = copyHead;

        while(current != nullptr)
        {
            if(current->random != nullptr)
            {
                Node* target = current->random;
                Node* ptr = head;
                Node* copyPtr = copyHead;
                while(true)
                {
                    if(ptr == target) 
                    {
                        copyCurrent->random = copyPtr;
                        break;
                    }
                    
                    ptr = ptr->next;
                    copyPtr = copyPtr->next;
                }
            }
            current = current->next;
            copyCurrent = copyCurrent->next;
        }
        
        return copyHead;
    }
    
    Node* copy_hashMap(Node* head)
    {
        if(head == nullptr) return nullptr;

        unordered_map<Node*, Node*> hashMap;
        
        Node* copyHead = new Node(head->val);
        Node* copyCurrent = copyHead;
        Node* current = head;
        hashMap.insert({current, copyCurrent});
        
        while(current->next != nullptr)
        {
            Node* newNode = new Node(current->next->val);
            copyCurrent->next = newNode;
                        
            copyCurrent = copyCurrent->next;
            current = current->next;
            
            hashMap.insert({current, copyCurrent});
        }
    
        copyCurrent = copyHead;
        current = head;
        
        while(copyCurrent != nullptr)
        {
            copyCurrent->random = hashMap[current->random];
            
            copyCurrent = copyCurrent->next;
            current = current->next;
        }
        
        return copyHead;
    }
    
    Node* copyRandomList(Node* head) {
        
        return copy_hashMap(head);        
    }
};