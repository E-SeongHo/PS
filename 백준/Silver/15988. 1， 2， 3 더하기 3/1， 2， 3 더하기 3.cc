#include <iostream>
#include <vector>

using namespace std;

int T;
#define Mod 1000000009

int main()
{
    // 2:01
    cin >> T;
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    vector<long long> dp(1000001);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i < dp.size(); ++i)
    {
        dp[i] = (dp[i] + dp[i-1]) % Mod;
        dp[i] = (dp[i] + dp[i-2]) % Mod;
        dp[i] = (dp[i] + dp[i-3]) % Mod;
    }

    for(int i = 0; i < T; ++i)
    {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}
