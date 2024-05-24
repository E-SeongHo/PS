#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> G;
vector<vector<int>> Ret;

void bfs(int start)
{
    vector<bool> visited(N, false);
    queue<int> q;

    q.push(start);
    // visited[start] = true;

    while(!q.empty())
    {
        int current = q.front(); q.pop();
        for(int i = 0; i < N; i++)
        {
            if(G[current][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;

                Ret[start][i] = 1;          
            }
        }
    }
}

int main()
{
    cin >> N;
    G.resize(N, vector<int>(N));
    Ret.resize(N, vector<int>(N));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> G[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        bfs(i);
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << Ret[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}