#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack
{
public:
    Stack() 
    {
        data.resize(10000);
    }
    void push(int e)
    {
        data[++topptr] = e;
    }
    int pop()
    {
        return topptr >= 0 ? data[topptr--] : -1;
    }
    int size()
    {
        return topptr+1;
    }
    bool empty()
    {
        return topptr < 0;
    }
    int top()
    {
        return topptr >= 0 ? data[topptr] : -1;
    }

private:
    vector<int> data;
    int topptr = -1;
};

int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    Stack s;

    for(int i = 0; i < n; ++i)
    {
        string operation;
        cin >> operation;
        
        if(operation == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if(operation == "pop")
        {
            cout << s.pop() << '\n';
        }
        else if(operation == "size")
        {
            cout << s.size() << '\n';
        }
        else if(operation == "empty")
        {
            cout << s.empty() << '\n';
        }
        else if(operation == "top")
        {
            cout << s.top() << '\n';
        }
    }

    return 0;
}