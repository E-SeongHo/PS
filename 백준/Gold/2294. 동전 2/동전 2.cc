#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> Coins;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    Coins.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> Coins[i];

    vector<int> dp(K+1, 999999);
    dp[0] = 0;

    for(int coin : Coins)
    {
        for(int i = coin; i < K+1; ++i)
        {
            dp[i] = min(dp[i], dp[i-coin] + 1);
        }
    }
    
    dp.back() == 999999 ? cout << -1 : cout << dp.back();

    return 0;
}