#include <iostream>
#include <vector>

using namespace std;

int N;
float fM;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    while(true)
    {
        cin >> N >> fM;
        if(N == 0 && fM == 0.0f) break;
        
        int M = fM * 100.0f + 0.5f;

        vector<int> calorie(N+1);
        vector<int> price(N+1);

        for(int i = 1; i < N+1; i++)
        {
            int c; float p;
            cin >> c >> p;
            calorie[i] = c;
            price[i] = p * 100.0f + 0.5f;
        }

        // vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
        // for(int i = 1; i <= N; i++)
        // {
        //     for(int j = 0; j <= M; j++)
        //     {
        //         if(j < price[i]) 
        //         {
        //             dp[i][j] = dp[i-1][j];
        //         } 
        //         else
        //         {
        //             int include = dp[i][j-price[i]] + calorie[i];
        //             int exclude = dp[i-1][j];
        //             dp[i][j] = max(include, exclude);
        //         }
        //     }
        // }

        vector<int> d(M+1, 0);
        for(int i = 1; i <= M; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(i-price[j] >= 0)
                {
                    d[i] = max(d[i], d[i-price[j]] + calorie[j]);
                }
            }
        }
        cout << d[M] << '\n';
        //cout << dp[N][M] << '\n';
    }

    return 0;
}
