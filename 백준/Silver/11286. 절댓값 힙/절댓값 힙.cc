#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Heap
{
public:
    Heap() = default;
    Heap(int n)
    {
        n = max(3, n);
        m_data.resize(n);
    }
    bool compare(int e1, int e2)
    {
        if(abs(e1) < abs(e2)) return true;
        else if(abs(e1) == abs(e2)) return e1 < e2;
        else return false;
    }
    void push(int e)
    {
        int current = ++m_size;
        m_data[current] = e;

        while(current != root)
        {
            int parent = current / 2;
            if(compare(m_data[current], m_data[parent]))
            {
                swap(m_data[current], m_data[parent]);
                current = parent;
            }
            else break;
        }
    }
    int pop()
    {
        if(m_size == 0) return 0;

        int ret = m_data[root];
        m_data[root] = m_data[m_size--];
        
        int current = root;
        while(current*2 <= m_size)
        {
            int left = current*2;
            int right = current*2 + 1;
            int child = right <= m_size && compare(m_data[right], m_data[left]) ? right : left;
            
            if(compare(m_data[child], m_data[current]))
            {
                swap(m_data[child], m_data[current]);
                current = child;
            }
            else break;
        }

        return ret;
    }

private:
    int root = 1;
    int m_size = 0;
    vector<int> m_data;
};

struct Compare
{
    bool operator()(const int e1, const int e2)
    {
        if(abs(e1) == abs(e2)) return e1 > e2;
        else return abs(e1) > abs(e2);
    }
};

int main()
{

    int N;
    cin >> N;
    //Heap absHeap(N);

    priority_queue<int, vector<int>, Compare> absHeap;

    for(int i = 0; i < N; ++i)
    {
        int command;
        cin >> command;
        if(command == 0) 
        {
            if(absHeap.empty()) cout << 0 << "\n";
            else 
            {
                cout << absHeap.top() << "\n";
                absHeap.pop();
            }
        }
        else
            absHeap.push(command);
    }


    return 0;
}
