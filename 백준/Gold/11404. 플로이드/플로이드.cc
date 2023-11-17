#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
int N, M;
vector<vector<int>> adjM;

int main()
{
    cin >> N >> M;
    adjM.resize(N+1, vector<int>(N+1, INF));
    for(int i = 1; i < N+1; ++i)
        adjM[i][i] = 0;

    for(int i = 0; i < M; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        adjM[from][to] = min(adjM[from][to], w);
    }

    for(int i = 1; i < N+1; ++i)
    {
        for(int j = 1; j < N+1; ++j)
        {
            for(int k = 1; k < N+1; ++k)
            {
                adjM[j][k] = min(adjM[j][k], adjM[j][i] + adjM[i][k]);
            }
        }
    }

    for(int i = 1; i < N+1; ++i)
    {
        for(int j = 1; j < N+1; ++j)
        {
            if(adjM[i][j] == INF) cout << 0 << " ";
            else cout << adjM[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}