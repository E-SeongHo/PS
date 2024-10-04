#include <iostream>
#include <vector>
#include <set>

using namespace std;

int T, N;
int A, B;
vector<int> Parents;
vector<vector<int>> Childs;

void dfs(int cur, vector<bool>& visited)
{
    visited[cur] = true;

    for(int child : Childs[cur])
        dfs(child, visited);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> N;
        Parents.resize(0); Childs.resize(0);
        Parents.resize(N+1); Childs.resize(N+1);

        for(int i = 0; i < N-1; ++i)
        {
            cin >> A >> B;
            Parents[B] = A;
            Childs[A].push_back(B);
        }

        cin >> A >> B;

        vector<bool> visited(N+1, false);
        int parent = A;
        while(parent)
        {
            dfs(parent, visited);
            if(visited[B]) break;
            
            parent = Parents[parent];
        }

        cout << parent << '\n';
    }
    return 0;
}