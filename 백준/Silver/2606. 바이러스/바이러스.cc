#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;

int cnt = 0;
void DFS(int n)
{
    visited[n] = true;
    cnt++;
    for(auto node : v[n])
    {
        if(!visited[node])
            DFS(node);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    v.resize(N+1);
    visited.resize(N+1);

    for(int i = 0; i < M; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;

        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }

    DFS(1);

    cout << cnt-1;

    return 0;
}