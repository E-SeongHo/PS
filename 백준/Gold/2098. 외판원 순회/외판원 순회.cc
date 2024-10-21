#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> W;
vector<vector<int>> DP;
constexpr int INF = 16000001;

int dfs(int start, int visit)
{
    if(!visit) return W[start][0];
    if(DP[start][visit]) return DP[start][visit];

    // dp[start][A] = start ~ i + DP[i][A - {i}]
    // visit에서 하나씩 뺀다.

    DP[start][visit] = INF;
    for(int i = 1; i < N; ++i)
    {
        if((visit & (1<<i)) == (1<<i))
        {
            int tmp = visit & ~(1<<i);
            DP[start][visit] = min(DP[start][visit], W[start][i] + dfs(i, tmp));
        }
    }

    return DP[start][visit];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    W.resize(N, vector<int>(N));

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> W[i][j];
            if(i != j && !W[i][j]) W[i][j] = INF;
        }
    }
    
    DP.resize(N, vector<int>(1<<N));
    // DP[i][j] start from i, and visit all j and visit back to 0
    for(int i = 0; i < N; ++i)
        DP[i][0] = W[i][0];

    int cost = dfs(0, ((1<<N)-1) & ~(1 << 0));
    
    cout << cost;

    return 0;
}