#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> V;

int main()
{
    cin >> N;
    V.resize(N);
    for(int& v : V) cin >> v;

    vector<int> dp(V.size());
    int ret = 0;

    for(int i = 0; i < V.size(); ++i)
    {
        dp[i] = V[i];
        for(int j = 0; j < i; ++j)
        {
            if(V[j] < V[i])
            {
                dp[i] = max(dp[j] + V[i], dp[i]);
            }
        }
        ret = max(ret, dp[i]);
    }
    
    cout << ret;
    return 0;
}