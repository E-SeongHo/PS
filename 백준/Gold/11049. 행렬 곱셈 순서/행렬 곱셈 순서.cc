#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> Matrices;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    Matrices.resize(N);
    for(int i = 0; i < N; ++i)
    {
        int n, m;
        cin >> n >> m;
        Matrices[i] = {n, m};
    }

    vector<vector<int>> dp(N+1, vector<int>(N, 2147483647));
    for(int i = 0; i < N-1; ++i)
    {
        dp[2][i] = Matrices[i].first * Matrices[i].second * Matrices[i+1].second;
    }
    
    for(int i = 3; i < N+1; ++i)
    {
        for(int j = 0; j < N-i+1; ++j)
        {
            for(int k = 1; k < i; ++k)
            {
                pair<int, int> left = {Matrices[j].first, Matrices[j+k-1].second};
                pair<int, int> right = {Matrices[j+k].first, Matrices[j+i-1].second};

                if(left.second != right.first) exit(-1);
                int mults = left.first * left.second * right.second;
                
                int leftsize = k;
                int rightsize = i-k;
                
                int leftprevs = k > 1 ? dp[k][j] : 0;
                int rightprevs = (i-k) > 1 ? dp[i-k][j+k] : 0;

                int total = mults + leftprevs + rightprevs;
                dp[i][j] = min(dp[i][j], total);
            }
        }
    }

    cout << dp[N][0];

    return 0;
}
