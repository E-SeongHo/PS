#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <stack>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

string solveWithSet(int n, int k, vector<string> cmd)
{
    string answer(n, 'X');
    
    int pointer = k;
    set<int> s;
    stack<int> deleted;
    for(int i = 0; i < n; i++) s.insert(i);
    
    for(int i = 0; i < cmd.size(); i++)
    {
        string command = cmd[i];
        if(command[0] == 'D')
        {
            int num = stoi(command.substr(2));
            pointer += num;
        }
        else if(command[0] == 'U')
        {
            int num = stoi(command.substr(2));
            pointer -= num;
        }
        else if(command[0] == 'C')
        {
            auto it = s.begin();
            advance(it, pointer);
            if(pointer == s.size()-1) pointer--;
            
            s.erase(it);
            deleted.push(*it);
        }
        else if(command[0] == 'Z')
        {
            auto it = s.begin();
            advance(it, pointer);
            
            int idx = deleted.top(); deleted.pop();
            if(*it > idx) pointer++;
            
            s.insert(idx);
        }
    }
    
    for(auto n : s) answer[n] = 'O';
    
    return answer;
}

struct Node
{
    int val;
    Node* prev;
    Node* next;
};

string solution(int n, int k, vector<string> cmd) {
    
    Node* head = new Node({0, nullptr, nullptr});
    Node* cursor = head;
    for(int i = 0; i < n; i++)
    {
        cursor->next = new Node({i, cursor, nullptr});
        cursor = cursor->next;
    }
    
    cursor = head->next;
    for(int i = 0; i < k; i++) cursor = cursor->next;
    
    stack<Node*> deleted;
    
    for(auto command : cmd)
    {
        if(command[0] == 'D')
        {
            int num = stoi(command.substr(2));
            for(int i = 0; i < num; i++) cursor = cursor->next;
        }
        else if(command[0] == 'U')
        {
            int num = stoi(command.substr(2));
            for(int i = 0; i < num; i++) cursor = cursor->prev;
        }
        else if(command[0] == 'C')
        {
            deleted.push(cursor);
            if(cursor->prev != nullptr) cursor->prev->next = cursor->next;
            if(cursor->next != nullptr) cursor->next->prev = cursor->prev;
            
            if(cursor->next == nullptr) cursor = cursor->prev;
            else cursor = cursor->next;
        }
        else if(command[0] == 'Z')
        {
            Node* restore = deleted.top(); deleted.pop();
            
            if(restore->prev != nullptr) restore->prev->next = restore;
            if(restore->next != nullptr) restore->next->prev = restore;
        }
    }
    
    string answer(n, 'X');
    
    cursor = head->next;
    while(cursor != nullptr)
    {
        answer[cursor->val] = 'O';
        cursor = cursor->next;
    }
    return answer;
}