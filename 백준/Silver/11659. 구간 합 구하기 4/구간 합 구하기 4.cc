#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<int> v(N+1);

    int sum = 0;
    for(int i = 1; i < N+1; ++i)
    {
        int in;
        cin >> in;
        sum += in;
        v[i] += sum;
    }

    for(int i = 0; i < M; ++i)
    {
        int start, end;
        cin >> start >> end;
        cout << v[end] - v[start-1] << "\n";
    }
}