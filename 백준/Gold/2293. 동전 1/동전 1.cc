#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> coins(N);
    for(int i = 0; i < N; ++i) 
        cin >> coins[i];

    vector<int> dp(K+1, 0);
    dp[0] = 1;

    for(int coin : coins) 
        for(int i = coin; i <= K; ++i) 
            dp[i] += dp[i - coin];

    cout << dp[K];
    return 0;
}