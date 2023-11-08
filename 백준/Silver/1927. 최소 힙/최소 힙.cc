#include <iostream>
#include <vector>

using namespace std;

class Heap
{
public:
    Heap() = default;
    Heap(int size) : m_data(size+1)
    {
        if(size < 3) m_data.resize(4);
    }
    void Push(int e)
    {
        int current = m_size++;
        m_data[current] = e;
        
        while(current != 1)
        {
            int parent = current / 2;
            if(m_data[parent] > m_data[current])
            {
                swap(m_data[parent], m_data[current]);
                current = parent;
            }
            else break;
        }
    }
    int Pop()
    {
        if(m_size == 1) return 0;

        int ret = m_data[1];

        m_data[1] = m_data[m_size-1];
        m_data[m_size-1] = 0;
        m_size--;

        int current = 1;

        while(current < m_size)
        {
            int left = 2*current;
            int right = 2*current + 1;

            int child;
            (m_data[left] > m_data[right]) && m_data[right] != 0 ? child = right : child = left;

            if((m_data[current] > m_data[child]) && m_data[child] != 0)
            {
                swap(m_data[current], m_data[child]);
                current = child;
            }
            else break;
        }
        return ret;
    }
    void Print()
    {
        for(auto n : m_data)
        {
            cout << n << " ";
        }
        cout << endl;
    }
private:
    vector<int> m_data;
    int m_size = 1;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    Heap heap = Heap(N);
    for(int i = 0; i < N; ++i)
    {
        int command;
        cin >> command;
        if(command == 0) cout << heap.Pop() << "\n";
        else heap.Push(command);
    }

    return 0;
}