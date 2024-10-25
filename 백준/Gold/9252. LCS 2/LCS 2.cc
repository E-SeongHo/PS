#include <iostream>
#include <vector>
#include <string>

using namespace std;

string A, B;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> B >> A;
    vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1));
    for(int i = 1; i < A.size()+1; ++i)
    {
        for(int j = 1; j < B.size()+1; ++j)
        {
            if(A[i-1] == B[j-1])
            {
                dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + 1);
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int y = A.size();
    int x = B.size();
    vector<char> ans;

    while(y)
    {
        if(dp[y][x] != dp[y][x-1])
        {
            if(dp[y][x] != dp[y-1][x])
            {
                ans.push_back(B[x-1]); 
                y = y-1;
                x = x-1;
            }
            else
            {
                y = y-1;
            }
        }
        else
        {
            x = x-1;
        }
    }

    cout << ans.size() << '\n';
    for(auto it = ans.rbegin(); it != ans.rend(); ++it)
    {
        cout << *it;
    }

    return 0;
}
