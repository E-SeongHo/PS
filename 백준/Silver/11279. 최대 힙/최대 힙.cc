#include <iostream>
#include <vector>

using namespace std;

class Heap
{
public:
    Heap() = default;
    Heap(int N)
    {
        N = max(N, 3);
        m_data.resize(N+1);
    }
    void push(int e)
    {
        int current = m_size++;
        m_data[current] = e;

        while(current != 1)
        {
            int parent = current / 2;
            if(m_data[current] > m_data[parent])
            {
                swap(m_data[current], m_data[parent]);
                current = parent;
            }
            else break;
        }
    }
    int pop()
    {
        if(m_size == 1) return 0;
        int ret = m_data[1];
        
        m_data[1] = m_data[--m_size];
        int current = 1;
        while(current*2 < m_size)
        {
            int left = current * 2;
            int right = current * 2 + 1;
            int bigger = m_data[left] > m_data[right] ? left : right;

            if(m_data[current] >= m_data[bigger]) break;

            swap(m_data[current], m_data[bigger]);
            current = bigger;
        }

        return ret;
    }
    void print()
    {
        for(int i = 1; i < m_size; ++i)
            cout << m_data[i] << " ";
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
    Heap heap(N);
    for(int i = 0; i < N; ++i)
    {
        int command;
        cin >> command;
        if(command == 0) cout << heap.pop() << "\n";
        else heap.push(command);
    }

    return 0;
}