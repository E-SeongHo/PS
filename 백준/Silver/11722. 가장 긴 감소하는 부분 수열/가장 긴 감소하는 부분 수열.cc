#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    V.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> V[i];

    vector<int> dp(N, 1);

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(V[i] < V[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}