#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Taken;
vector<int> Cost;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    Taken.resize(N+1); Cost.resize(N+1);

    for(int i = 1; i < N+1; ++i)
        cin >> Taken[i];

    for(int i = 1; i < N+1; ++i)
        cin >> Cost[i];

    vector<vector<int>> dp(N+1, vector<int>(100 * N + 1, 0));

    // dp[N][C] : N개까지 고려해서, Cost이하 사용하는 Memory 최댓값
    for(int i = 1; i < N+1; ++i)
    {
        for(int c = 0; c < dp[0].size(); ++c)
        {
            if(Cost[i] <= c)
            {
                dp[i][c] = max(dp[i-1][c-Cost[i]] + Taken[i], dp[i-1][c]);
            }
            else
            {
                dp[i][c] = dp[i-1][c];
            }
        }
    }

    for(int i = 0; i < dp[0].size(); ++i)
    {
        if(dp[N][i] >= M)
        {
            cout << i;
            break;
        }
    }

    return 0;
}
