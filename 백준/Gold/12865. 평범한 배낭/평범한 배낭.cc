#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, W, V;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    cin >> N >> K;
    vector<pair<int, int>> items(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> W >> V;
        items[i] = {W, V};
    }

    sort(items.begin(), items.end());
    vector<int> dp(K+1);

    dp[0] = 0;
    for(auto [weight, value] : items)
    {
        vector<int> original = dp;
        for(int i = weight; i < K+1; ++i)
        {
            dp[i] = max(original[i], original[i-weight] + value);
        }
    }

    cout << dp[K];
    return 0;
}