#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> SmallStep;
vector<int> BigStep;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    SmallStep.resize(N+1); BigStep.resize(N+1);
    for(int i = 1; i < N; ++i)
        cin >> SmallStep[i] >> BigStep[i];
    cin >> K;

    vector<vector<int>> dp(2, vector<int>(N+1, 99999999));
    dp[0][1] = 0; dp[1][1] = 0;
    dp[0][2] = SmallStep[1];

    for(int i = 3; i < N+1; ++i)
    {
        dp[0][i] = min(dp[0][i-1] + SmallStep[i-1], dp[0][i-2] + BigStep[i-2]);
        dp[1][i] = min(min(dp[0][i-3] + K, dp[1][i-1] + SmallStep[i-1]), dp[1][i-2] + BigStep[i-2]);
    }

    cout << min(dp[0][N], dp[1][N]);

    return 0;
}
