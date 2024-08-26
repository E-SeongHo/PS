#include <iostream>
#include <vector>

using namespace std;

int N;
int main()
{
    cin >> N;
    vector<int> dp(N+1, 999999999);

    dp[0] = 0;

    for(int i = 1; i < N+1; ++i)
        for(int j = 1; j*j <= i; ++j)
            dp[i] = min(dp[i], dp[i-j*j] + 1);
    
    cout << dp[N];

    return 0;
}