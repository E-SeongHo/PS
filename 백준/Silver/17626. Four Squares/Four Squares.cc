#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;

int main()
{
    cin >> N;
    dp.resize(N+1);
    std::fill(dp.begin(), dp.end(), 99999);

    dp[0] = 0;
    for(int i = 1; i < dp.size(); i++)
    {
        for(int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }

    cout << dp[N];

    return 0;
}