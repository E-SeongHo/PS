#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> Map;
constexpr int INF = 99999999;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    Map.resize(N+1, vector<int>(N+1, INF));

    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        Map[a][b] = 1;
    }

    for(int k = 1; k < N+1; ++k)
    {
        for(int i = 1; i < N+1; ++i)
        {
            for(int j = 1; j < N+1; ++j)
            {
                Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
            }
        }
    }

    vector<int> ans(N+1, 0);
    for(int i = 1; i < N+1; ++i)
    {
        for(int j = 1; j < N+1; ++j)
        {
            if(i == j) continue;

            if(Map[i][j] != INF || Map[j][i] != INF)
            {
                ans[i]++;
            }
        }

        cout << N-1 - ans[i] << '\n';
    }

    return 0;
}
