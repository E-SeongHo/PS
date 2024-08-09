#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> V;
vector<int> DP;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    V.resize(N+1);
    for(int i = 1; i < N+1; ++i)
    {
        int t, p;
        cin >> t >> p;
        V[i] = {t, p};
    }

    DP.resize(N+1);
    int maxPrice = 0;
    for(int i = 1; i < N+1; ++i)
    {
        auto [t, p] = V[i];
        maxPrice = max(maxPrice, DP[i]);

        if(i + t <= N+1)
        {
            DP[i] = max(max(DP[i], DP[i] + p), maxPrice + p);
            if(i+t <= N) DP[i+t] = max(DP[i+t], DP[i]);
        }

        DP[i] = max(DP[i], DP[i-1]);
    }

    cout << DP[N];

    return 0;
}