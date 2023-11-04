#include <iostream>
#include <vector>

using namespace std;
using p = pair<int, int>;

int N, K;
vector<p> items;
vector<vector<int>> dp;

void Print()
{
    for(int i = 0; i < N+1; ++i)
    {
        for(int j = 0; j < K+1; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> N >> K;
    items.reserve(N+1);
    dp.resize(N+1, vector<int>(K+1));

    items.push_back({0, 0});
    for(int i = 1; i < N+1; ++i)
    {
        int item, value;
        cin >> item >> value;
        items.push_back({item, value});
    }

    for(int i = 1; i < N+1; ++i)
    {
        int weight = items[i].first;
        int value = items[i].second;

        //cout << weight << " " << value << endl;
        for(int j = 1; j < K+1; ++j)
        {
            if(j - weight >= 0)
                dp[i][j] = max(dp[i-1][j], value + dp[i-1][j-weight]); 

            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

        }
        
        //Print();
    }
    
    cout << dp[N][K];

    return 0;
}