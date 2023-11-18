#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> table;
vector<vector<int>> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    table.resize(N+1, vector<int>(N+1));
    dp.resize(N+1, vector<int>(N+1));
    

    for(int i = 1; i < N+1; ++i)
    {
        for(int j = 1; j < N+1; ++j)
        {
            cin >> table[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + table[i][j] - dp[i-1][j-1];
        }
    }

    for(int i = 0; i < M; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ret = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
        cout << ret << "\n";;
    }
    return 0;
}