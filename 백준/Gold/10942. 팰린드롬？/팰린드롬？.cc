#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> V;
int S, E;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    V.resize(N+1);

    for(int i = 1; i < N+1; ++i)
        cin >> V[i];

    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
    for(int i = 1; i < N+1; ++i)
    {
        dp[0][i] = 1;
        dp[1][i] = 1;
    }

    for(int i = 2; i < N+1; ++i)
    {
        for(int j = 1; j <= N+1-i; ++j)
        {   
            if(dp[i-2][j+1])
            {
                if(V[j] == V[j+i-1]) dp[i][j] = 1;
            }
        }
    }   

    cin >> M;

    for(int i = 0; i < M; ++i)
    {
        cin >> S >> E;

        cout << dp[E-S+1][S] << '\n';
    }

    return 0;
}