#include <iostream>
#include <vector>
using namespace std;

int T;
vector<pair<int, int>> dp;

int main()
{
    dp.resize(41);
    dp[0].first = 1;
    dp[0].second = 0;

    dp[1].first = 0;
    dp[1].second = 1;

    for(int i = 2; i < dp.size(); ++i)
    {
        dp[i].first = dp[i-1].first + dp[i-2].first;
        dp[i].second = dp[i-1].second + dp[i-2].second;
    }

    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int n;
        cin >> n;
        cout << dp[n].first << " " << dp[n].second << "\n";
    }
    return 0;
}