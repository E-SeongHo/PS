#include <iostream>
#include <vector>

using namespace std;

int N;
int main()
{
    cin >> N;
    vector<int> dp(max(5, N+1));

    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;

    for(int i = 5; i < N+1; ++i)
    {
        dp[i] = (!dp[i-1] || !dp[i-3] || !dp[i-4]);
    }

    dp[N] ? cout << "SK" : cout << "CY";

    return 0;
}