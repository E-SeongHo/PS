#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> Parent;
vector<vector<int>> Childs;

vector<int> Sum;

void dfs(int cur)
{
    if(Childs[cur].empty()) return;

    for(int child : Childs[cur])
    {
        Sum[child] += Sum[cur];
        dfs(child);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    Parent.resize(N+1); Childs.resize(N+1); Sum.resize(N+1);
    for(int i = 1; i <= N; ++i)
    {
        cin >> Parent[i];
        if(Parent[i] == -1) continue;

        Childs[Parent[i]].push_back(i);
    }

    for(int i = 0; i < M; ++i)
    {
        int n, w;
        cin >> n >> w;

        Sum[n] += w;
    }

    dfs(1);

    for(int i = 1; i <= N; ++i)
    {
        cout << Sum[i] << " ";
    }


    return 0;
}
