#include <iostream>
#include <vector>

using namespace std;

int T, N, M;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> N;
        vector<int> coins(N);
        for(int i = 0; i < N; ++i)
            cin >> coins[i];

        cin >> M;
        vector<int> dp(M+1);

        dp[0] = 1;
        for(auto coin : coins)
            for(int i = coin; i < M+1; ++i)
                dp[i] = dp[i] + dp[i-coin];

        cout << dp[M] << "\n";
    }
    return 0;
}