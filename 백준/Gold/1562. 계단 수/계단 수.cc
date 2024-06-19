#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<vector<long long>>> dp;

int main()
{
    cin >> N;
    dp.resize(N+1, vector<vector<long long>>(10, vector<long long>(1024, 0)));

    for(int i = 1; i < N+1; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i == 1)
            {
                if(j == 0) continue;

                int k = 1 << j;
                dp[i][j][k]++;
            }
            else
            {
                for(int k = 0; k < 1024; k++)
                {
                    int bit = k | (1 << j);

                    if(j-1 >= 0)
                    {
                       dp[i][j][bit] = (dp[i][j][bit] + dp[i-1][j-1][k]) % 1000000000;
                    }
                    if(j+1 < 10)
                    {
                       dp[i][j][bit] = (dp[i][j][bit] + dp[i-1][j+1][k]) % 1000000000;
                    }
                }
            }
        }
    }

    long long ret = 0;

    for(int i = 0; i < 10; i++)
    {
        ret = (ret + dp[N][i][1023]) % 1000000000;
    }
    
    cout << ret;


    return 0;
}