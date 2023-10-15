#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> ops; // 0, 1, 2, 3
int M = -1987654321;
int m = 1987654321;

vector<int> arr;

void UpdateMinMax()
{
    int sum = v[0];
    for(int i = 0; i < N-1; ++i)
    {
        switch (arr[i])
        {
        case 0:
            sum+= v[i+1];
            break;
        case 1:
            sum-= v[i+1];
            break;
        case 2:
            sum*= v[i+1];
            break;
        case 3:
            sum/= v[i+1];
            break;
        }
    }
    M = max(sum, M);
    m = min(sum, m);
}

void DFS(int depth)
{
    if(depth == N-1)
    {
        UpdateMinMax();
        return;
    }

    for(int i = 0; i < 4; ++i)
    {
        if(ops[i])
        {
            arr[depth] = i;
            ops[i]--;
            DFS(depth+1);
            ops[i]++;
        }
        
    }
}

int main()
{
    cin >> N;
    v.resize(N);
    ops.resize(4);
    
    arr.resize(N-1);
    for(int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }
    for(int i = 0; i < 4; ++i)
    {
        cin >> ops[i];
    }

    DFS(0);

    cout << M << "\n";
    cout << m << "\n";
    
    return 0;
}